--- src/freebsd_pci.c.orig	2017-10-23 15:48:29 UTC
+++ src/freebsd_pci.c
@@ -43,6 +43,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#if defined(__i386__) || defined(__amd64__)
+#include <machine/cpufunc.h>
+#else
+#include <dev/io/iodev.h>
+#endif
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/pciio.h>
@@ -52,31 +57,35 @@
 #include "pciaccess.h"
 #include "pciaccess_private.h"
 
-#define	PCIC_DISPLAY	0x03
+#define	PCIC_DISPLAY		0x03
 #define	PCIS_DISPLAY_VGA	0x00
 #define	PCIS_DISPLAY_XGA	0x01
 #define	PCIS_DISPLAY_3D		0x02
 #define	PCIS_DISPLAY_OTHER	0x80
 
 /* Registers taken from pcireg.h */
-#define PCIR_COMMAND    0x04
-#define PCIM_CMD_PORTEN         0x0001
-#define PCIM_CMD_MEMEN          0x0002
-#define PCIR_BIOS	0x30
+#define PCIR_COMMAND		0x04
+#define PCIM_CMD_PORTEN		0x0001
+#define PCIM_CMD_MEMEN		0x0002
+#define PCIR_BIOS		0x30
 #define PCIM_BIOS_ENABLE	0x01
 #define PCIM_BIOS_ADDR_MASK	0xfffff800
 
-#define PCIR_BARS       0x10
-#define PCIR_BAR(x)             (PCIR_BARS + (x) * 4)
-#define PCI_BAR_IO(x)           (((x) & PCIM_BAR_SPACE) == PCIM_BAR_IO_SPACE)
-#define PCI_BAR_MEM(x)          (((x) & PCIM_BAR_SPACE) == PCIM_BAR_MEM_SPACE)
-#define PCIM_BAR_MEM_TYPE       0x00000006
-#define PCIM_BAR_MEM_64         4
-#define PCIM_BAR_MEM_PREFETCH   0x00000008
-#define PCIM_BAR_SPACE          0x00000001
-#define PCIM_BAR_MEM_SPACE      0
-#define PCIM_BAR_IO_SPACE       1
+#define PCIR_BARS		0x10
+#define PCIR_BAR(x)		(PCIR_BARS + (x) * 4)
+#define PCI_BAR_IO(x)		(((x) & PCIM_BAR_SPACE) == PCIM_BAR_IO_SPACE)
+#define PCI_BAR_MEM(x)		(((x) & PCIM_BAR_SPACE) == PCIM_BAR_MEM_SPACE)
+#define PCIM_BAR_MEM_TYPE	0x00000006
+#define PCIM_BAR_MEM_64		4
+#define PCIM_BAR_MEM_PREFETCH	0x00000008
+#define PCIM_BAR_SPACE		0x00000001
+#define PCIM_BAR_MEM_SPACE	0
+#define PCIM_BAR_IO_SPACE	1
 
+#if defined(__sparc64__)
+static int screenfd;
+#endif
+
 /**
  * FreeBSD private pci_system structure that extends the base pci_system
  * structure.
@@ -103,17 +112,23 @@ struct freebsd_pci_system {
  * Zero on success or an \c errno value on failure.
  */
 static int
-pci_device_freebsd_map_range(struct pci_device *dev,
-			     struct pci_device_mapping *map)
+pci_device_freebsd_map_range( struct pci_device *dev,
+			      struct pci_device_mapping *map )
 {
     const int prot = ((map->flags & PCI_DEV_MAP_FLAG_WRITABLE) != 0)
         ? (PROT_READ | PROT_WRITE) : PROT_READ;
+#if !defined(__sparc64__)
     struct mem_range_desc mrd;
     struct mem_range_op mro;
+#endif
 
     int fd, err = 0;
 
+#if defined(__sparc64__)
+    fd = screenfd;
+#else
     fd = open("/dev/mem", O_RDWR | O_CLOEXEC);
+#endif
     if (fd == -1)
 	return errno;
 
@@ -123,6 +138,7 @@ pci_device_freebsd_map_range(struct pci_device *dev,
 	err = errno;
     }
 
+#if !defined(__sparc64__)
     mrd.mr_base = map->base;
     mrd.mr_len = map->size;
     strncpy(mrd.mr_owner, "pciaccess", sizeof(mrd.mr_owner));
@@ -143,6 +159,7 @@ pci_device_freebsd_map_range(struct pci_device *dev,
     }
 
     close(fd);
+#endif
 
     return err;
 }
@@ -151,6 +168,7 @@ static int
 pci_device_freebsd_unmap_range( struct pci_device *dev,
 				struct pci_device_mapping *map )
 {
+#if !defined(__sparc64__)
     struct mem_range_desc mrd;
     struct mem_range_op mro;
     int fd;
@@ -176,6 +194,7 @@ pci_device_freebsd_unmap_range( struct pci_device *dev
 	    fprintf(stderr, "Failed to open /dev/mem\n");
 	}
     }
+#endif
 
     return pci_device_generic_unmap_range(dev, map);
 }
@@ -187,9 +206,7 @@ pci_device_freebsd_read( struct pci_device * dev, void
 {
     struct pci_io io;
 
-#if HAVE_PCI_IO_PC_DOMAIN
     io.pi_sel.pc_domain = dev->domain;
-#endif
     io.pi_sel.pc_bus = dev->bus;
     io.pi_sel.pc_dev = dev->dev;
     io.pi_sel.pc_func = dev->func;
@@ -227,9 +244,7 @@ pci_device_freebsd_write( struct pci_device * dev, con
 {
     struct pci_io io;
 
-#if HAVE_PCI_IO_PC_DOMAIN
     io.pi_sel.pc_domain = dev->domain;
-#endif
     io.pi_sel.pc_bus = dev->bus;
     io.pi_sel.pc_dev = dev->dev;
     io.pi_sel.pc_func = dev->func;
@@ -298,7 +313,11 @@ pci_device_freebsd_read_rom( struct pci_device * dev, 
     }
 
     printf("Using rom_base = 0x%lx\n", (long)rom_base);
+#if defined(__sparc64__)
+    memfd = screenfd;
+#else
     memfd = open( "/dev/mem", O_RDONLY | O_CLOEXEC );
+#endif
     if ( memfd == -1 )
 	return errno;
 
@@ -311,7 +330,9 @@ pci_device_freebsd_read_rom( struct pci_device * dev, 
     memcpy( buffer, bios, dev->rom_size );
 
     munmap( bios, dev->rom_size );
+#if !defined(__sparc64__)
     close( memfd );
+#endif
 
     if (pci_rom) {
 	pci_device_cfg_write_u32( dev, PCIR_BIOS, rom );
@@ -341,19 +362,14 @@ pci_device_freebsd_get_num_regions( struct pci_device 
     }
 }
 
-#ifdef PCIOCGETBAR
-
 static int
 pci_device_freebsd_probe( struct pci_device * dev )
 {
-    struct pci_device_private *priv = (struct pci_device_private *) dev;
     struct pci_bar_io bar;
     uint8_t irq;
     int err, i;
 
-#if HAVE_PCI_IO_PC_DOMAIN
     bar.pbi_sel.pc_domain = dev->domain;
-#endif
     bar.pbi_sel.pc_bus = dev->bus;
     bar.pbi_sel.pc_dev = dev->dev;
     bar.pbi_sel.pc_func = dev->func;
@@ -397,307 +413,191 @@ pci_device_freebsd_probe( struct pci_device * dev )
      return 0;
 }
 
-#else
-
-/** Masks out the flag bigs of the base address register value */
-static uint32_t
-get_map_base( uint32_t val )
+static void
+pci_system_freebsd_destroy( void )
 {
-    if (val & 0x01)
-	return val & ~0x03;
-    else
-	return val & ~0x0f;
+    close(freebsd_pci_sys->pcidev);
+    free(freebsd_pci_sys->pci_sys.devices);
+    freebsd_pci_sys = NULL;
 }
 
-/** Returns the size of a region based on the all-ones test value */
 static int
-get_test_val_size( uint32_t testval )
+pci_device_freebsd_has_kernel_driver( struct pci_device *dev )
 {
-    if (testval == 0)
-	return 0;
+    struct pci_io io;
 
-    /* Mask out the flag bits */
-    testval = get_map_base( testval );
-
-    return 1 << (ffs(testval) - 1);
-}
-
-/**
- * Sets the address and size information for the region from config space
- * registers.
- *
- * This would be much better provided by a kernel interface.
- *
- * \return 0 on success, or an errno value.
- */
-static int
-pci_device_freebsd_get_region_info( struct pci_device * dev, int region,
-				    int bar )
-{
-    uint32_t addr, testval;
-    uint16_t cmd;
-    int err;
-
-    /* Get the base address */
-    err = pci_device_cfg_read_u32( dev, &addr, bar );
-    if (err != 0)
-	return err;
-
-    /*
-     * We are going to be doing evil things to the registers here
-     * so disable them via the command register first.
-     */
-    err = pci_device_cfg_read_u16( dev, &cmd, PCIR_COMMAND );
-    if (err != 0)
-	return err;
-
-    err = pci_device_cfg_write_u16( dev,
-	cmd & ~(PCI_BAR_MEM(addr) ? PCIM_CMD_MEMEN : PCIM_CMD_PORTEN),
-	PCIR_COMMAND );
-    if (err != 0)
-	return err;
-
-    /* Test write all ones to the register, then restore it. */
-    err = pci_device_cfg_write_u32( dev, 0xffffffff, bar );
-    if (err != 0)
-	return err;
-    err = pci_device_cfg_read_u32( dev, &testval, bar );
-    if (err != 0)
-	return err;
-    err = pci_device_cfg_write_u32( dev, addr, bar );
-    if (err != 0)
-	return err;
-
-    /* Restore the command register */
-    err = pci_device_cfg_write_u16( dev, cmd, PCIR_COMMAND );
-    if (err != 0)
-	return err;
-
-    if (addr & 0x01)
-	dev->regions[region].is_IO = 1;
-    if (addr & 0x04)
-	dev->regions[region].is_64 = 1;
-    if (addr & 0x08)
-	dev->regions[region].is_prefetchable = 1;
-
-    /* Set the size */
-    dev->regions[region].size = get_test_val_size( testval );
-	printf("size = 0x%lx\n", (long)dev->regions[region].size);
-
-    /* Set the base address value */
-    if (dev->regions[region].is_64) {
-	uint32_t top;
-
-	err = pci_device_cfg_read_u32( dev, &top, bar + 4 );
-	if (err != 0)
-	    return err;
-
-	dev->regions[region].base_addr = ((uint64_t)top << 32) |
-					  get_map_base(addr);
-    } else {
-	dev->regions[region].base_addr = get_map_base(addr);
+    io.pi_sel.pc_domain = dev->domain;
+    io.pi_sel.pc_bus = dev->bus;
+    io.pi_sel.pc_dev = dev->dev;
+    io.pi_sel.pc_func = dev->func;
+    
+    if ( ioctl( freebsd_pci_sys->pcidev, PCIOCATTACHED, &io ) < 0 ) {
+	return 0;
     }
 
-    return 0;
+    /* if io.pi_data is 0, no driver is attached */
+    return io.pi_data == 0 ? 0 : 1;
 }
 
-static int
-pci_device_freebsd_probe( struct pci_device * dev )
+static struct pci_io_handle *
+pci_device_freebsd_open_legacy_io( struct pci_io_handle *ret,
+				   struct pci_device *dev, pciaddr_t base,
+				   pciaddr_t size )
 {
-    struct pci_device_private *priv = (struct pci_device_private *) dev;
-    uint32_t reg, size;
-    uint8_t irq;
-    int err, i, bar;
-
-    /* Many of the fields were filled in during initial device enumeration.
-     * At this point, we need to fill in regions, rom_size, and irq.
-     */
-
-    err = pci_device_cfg_read_u8( dev, &irq, 60 );
-    if (err)
-	return errno;
-    dev->irq = irq;
-
-    bar = 0x10;
-    for (i = 0; i < pci_device_freebsd_get_num_regions( dev ); i++) {
-	pci_device_freebsd_get_region_info( dev, i, bar );
-	if (dev->regions[i].is_64) {
-	    bar += 0x08;
-	    i++;
-	} else
-	    bar += 0x04;
-    }
-
-    /* If it's a VGA device, set up the rom size for read_rom */
-    if ((dev->device_class & 0x00ffff00) ==
-	((PCIC_DISPLAY << 16) | (PCIS_DISPLAY_VGA << 8)))
-    {
-	err = pci_device_cfg_read_u32( dev, &reg, PCIR_BIOS );
-	if (err)
-	    return errno;
-
-	if (reg == 0) {
-	    dev->rom_size = 0x10000;
-	    return 0;
-	}
-
-	err = pci_device_cfg_write_u32( dev, ~PCIM_BIOS_ENABLE, PCIR_BIOS );
-	if (err)
-	    return errno;
-	pci_device_cfg_read_u32( dev, &size, PCIR_BIOS );
-	pci_device_cfg_write_u32( dev, reg, PCIR_BIOS );
-
-	if ((reg & PCIM_BIOS_ADDR_MASK) != 0) {
-	    priv->rom_base = (reg & PCIM_BIOS_ADDR_MASK);
-	    dev->rom_size = -(size & PCIM_BIOS_ADDR_MASK);
-	}
-    }
-
-    return 0;
-}
-
+#if defined(__sparc64__)
+    ret->memory = mmap( NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
+	screenfd, base );
+    if ( ret->memory == MAP_FAILED )
+	return NULL;
+#else
+    ret->fd = open( "/dev/io", O_RDWR | O_CLOEXEC );
+    if ( ret->fd < 0 )
+	return NULL;
 #endif
-
-static void
-pci_system_freebsd_destroy(void)
-{
-    close(freebsd_pci_sys->pcidev);
-    free(freebsd_pci_sys->pci_sys.devices);
-    freebsd_pci_sys = NULL;
+    ret->base = base;
+    ret->size = size;
+    ret->is_legacy = 1;
+    return ret;
 }
 
-#if defined(__i386__) || defined(__amd64__)
-#include <machine/cpufunc.h>
-#endif
-
 static struct pci_io_handle *
-pci_device_freebsd_open_legacy_io(struct pci_io_handle *ret,
-    struct pci_device *dev, pciaddr_t base, pciaddr_t size)
+pci_device_freebsd_open_io( struct pci_io_handle *ret,
+			    struct pci_device *dev, int bar,
+			    pciaddr_t base, pciaddr_t size )
 {
-#if defined(__i386__) || defined(__amd64__)
-	ret->fd = open("/dev/io", O_RDWR | O_CLOEXEC);
-
-	if (ret->fd < 0)
-		return NULL;
-
-	ret->base = base;
-	ret->size = size;
-	ret->is_legacy = 1;
-	return ret;
-#elif defined(PCI_MAGIC_IO_RANGE)
-	ret->memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
-	    aperturefd, PCI_MAGIC_IO_RANGE + base);
-	if (ret->memory == MAP_FAILED)
-		return NULL;
-
-	ret->base = base;
-	ret->size = size;
-	ret->is_legacy = 1;
-	return ret;
-#else
-	return NULL;
-#endif
+    ret = pci_device_freebsd_open_legacy_io( ret, dev, base, size );
+    if ( ret != NULL )
+	ret->is_legacy = 0;
+    return ret;
 }
 
-#if defined(__i386__) || defined(__amd64__)
 static void
-pci_device_freebsd_close_io(struct pci_device *dev, struct pci_io_handle *handle)
+pci_device_freebsd_close_io( struct pci_device *dev,
+			     struct pci_io_handle *handle )
 {
-	if (handle->fd > -1)
-		close(handle->fd);
-}
+#if !defined(__sparc64__)
+    if ( handle->fd > -1 )
+	close( handle->fd );
 #endif
+}
 
 static uint32_t
-pci_device_freebsd_read32(struct pci_io_handle *handle, uint32_t reg)
+pci_device_freebsd_read32( struct pci_io_handle *handle, uint32_t reg )
 {
-#if defined(__i386__) || defined(__amd64__)
-	return inl(handle->base + reg);
+#if defined(__sparc64__)
+    return *(uint32_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inl( handle->base + reg );
 #else
-	return *(uint32_t *)((uintptr_t)handle->memory + reg);
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 4, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
 #endif
 }
 
 static uint16_t
-pci_device_freebsd_read16(struct pci_io_handle *handle, uint32_t reg)
+pci_device_freebsd_read16( struct pci_io_handle *handle, uint32_t reg )
 {
-#if defined(__i386__) || defined(__amd64__)
-	return inw(handle->base + reg);
+#if defined(__sparc64__)
+    return *(uint16_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inw( handle->base + reg );
 #else
-	return *(uint16_t *)((uintptr_t)handle->memory + reg);
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 2, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
 #endif
 }
 
 static uint8_t
-pci_device_freebsd_read8(struct pci_io_handle *handle, uint32_t reg)
+pci_device_freebsd_read8( struct pci_io_handle *handle, uint32_t reg )
 {
-#if defined(__i386__) || defined(__amd64__)
-	return inb(handle->base + reg);
+#if defined(__sparc64__)
+    return *(uint8_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inb( handle->base + reg );
 #else
-	return *(uint8_t *)((uintptr_t)handle->memory + reg);
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 1, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
 #endif
 }
 
 static void
-pci_device_freebsd_write32(struct pci_io_handle *handle, uint32_t reg,
-    uint32_t data)
+pci_device_freebsd_write32( struct pci_io_handle *handle, uint32_t reg,
+			    uint32_t data )
 {
-#if defined(__i386__) || defined(__amd64__)
-	outl(handle->base + reg, data);
+#if defined(__sparc64__)
+    *(uint32_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outl( handle->base + reg, data );
 #else
-	*(uint16_t *)((uintptr_t)handle->memory + reg) = data;
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 4, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
 #endif
 }
 
 static void
-pci_device_freebsd_write16(struct pci_io_handle *handle, uint32_t reg,
-    uint16_t data)
+pci_device_freebsd_write16( struct pci_io_handle *handle, uint32_t reg,
+			    uint16_t data )
 {
-#if defined(__i386__) || defined(__amd64__)
-	outw(handle->base + reg, data);
+#if defined(__sparc64__)
+    *(uint16_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outw( handle->base + reg, data );
 #else
-	*(uint8_t *)((uintptr_t)handle->memory + reg) = data;
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 2, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
 #endif
 }
 
 static void
-pci_device_freebsd_write8(struct pci_io_handle *handle, uint32_t reg,
-    uint8_t data)
+pci_device_freebsd_write8( struct pci_io_handle *handle, uint32_t reg,
+			   uint8_t data )
 {
-#if defined(__i386__) || defined(__amd64__)
-	outb(handle->base + reg, data);
+#if defined(__sparc64__)
+    *(uint8_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outb( handle->base + reg, data );
 #else
-	*(uint32_t *)((uintptr_t)handle->memory + reg) = data;
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 1, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
 #endif
 }
 
 static int
-pci_device_freebsd_map_legacy(struct pci_device *dev, pciaddr_t base,
-    pciaddr_t size, unsigned map_flags, void **addr)
+pci_device_freebsd_map_legacy( struct pci_device *dev, pciaddr_t base,
+			       pciaddr_t size, unsigned map_flags, void **addr )
 {
-	struct pci_device_mapping map;
-	int err;
+    struct pci_device_mapping map;
+    int err;
 
-	map.base = base;
-	map.size = size;
-	map.flags = map_flags;
-	map.memory = NULL;
-	err = pci_device_freebsd_map_range(dev, &map);
-	*addr = map.memory;
+    map.base = base;
+    map.size = size;
+    map.flags = map_flags;
+    map.memory = NULL;
+    err = pci_device_freebsd_map_range( dev, &map );
+    *addr = map.memory;
 
-	return err;
+    return err;
 }
 
 static int
-pci_device_freebsd_unmap_legacy(struct pci_device *dev, void *addr,
-    pciaddr_t size)
+pci_device_freebsd_unmap_legacy( struct pci_device *dev, void *addr,
+				 pciaddr_t size )
 {
-	struct pci_device_mapping map;
+    struct pci_device_mapping map;
 
-	map.memory = addr;
-	map.size = size;
-	map.flags = 0;
-	return pci_device_freebsd_unmap_range(dev, &map);
+    map.memory = addr;
+    map.size = size;
+    map.flags = 0;
+    return pci_device_freebsd_unmap_range( dev, &map );
 }
 
 static const struct pci_system_methods freebsd_pci_methods = {
@@ -707,19 +607,25 @@ static const struct pci_system_methods freebsd_pci_met
     .probe = pci_device_freebsd_probe,
     .map_range = pci_device_freebsd_map_range,
     .unmap_range = pci_device_freebsd_unmap_range,
+
     .read = pci_device_freebsd_read,
     .write = pci_device_freebsd_write,
+
     .fill_capabilities = pci_fill_capabilities_generic,
+    .enable = NULL,
+    .boot_vga = NULL,
+    .has_kernel_driver = pci_device_freebsd_has_kernel_driver,
+
+    .open_device_io = pci_device_freebsd_open_io,
     .open_legacy_io = pci_device_freebsd_open_legacy_io,
-#if defined(__i386__) || defined(__amd64__)
     .close_io = pci_device_freebsd_close_io,
-#endif
     .read32 = pci_device_freebsd_read32,
     .read16 = pci_device_freebsd_read16,
     .read8 = pci_device_freebsd_read8,
     .write32 = pci_device_freebsd_write32,
     .write16 = pci_device_freebsd_write16,
     .write8 = pci_device_freebsd_write8,
+
     .map_legacy = pci_device_freebsd_map_legacy,
     .unmap_legacy = pci_device_freebsd_unmap_legacy,
 };
@@ -775,11 +681,7 @@ pci_system_freebsd_create( void )
     for ( i = 0; i < pciconfio.num_matches; i++ ) {
 	struct pci_conf *p = &pciconf[ i ];
 
-#if HAVE_PCI_IO_PC_DOMAIN
 	pci_sys->devices[ i ].base.domain = p->pc_sel.pc_domain;
-#else
-	pci_sys->devices[ i ].base.domain = 0;
-#endif
 	pci_sys->devices[ i ].base.bus = p->pc_sel.pc_bus;
 	pci_sys->devices[ i ].base.dev = p->pc_sel.pc_dev;
 	pci_sys->devices[ i ].base.func = p->pc_sel.pc_func;
@@ -794,4 +696,12 @@ pci_system_freebsd_create( void )
     }
 
     return 0;
+}
+
+void
+pci_system_freebsd_init_dev_mem(int fd)
+{
+#if defined(__sparc64__)
+    screenfd = fd;
+#endif
 }
