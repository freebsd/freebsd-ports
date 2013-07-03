--- src/freebsd_pci.c.orig	2012-04-09 13:02:57.000000000 -0400
+++ src/freebsd_pci.c	2013-06-18 19:29:20.000000000 -0400
@@ -1,6 +1,8 @@
 /*
  * (C) Copyright Eric Anholt 2006
  * (C) Copyright IBM Corporation 2006
+ * (C) Copyright Mark Kettenis 2011
+ * (C) Copyright Robert Millan 2012
  * All Rights Reserved.
  *
  * Permission is hereby granted, free of charge, to any person obtaining a
@@ -37,6 +39,11 @@
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
@@ -72,6 +79,10 @@
 #define PCIM_BAR_MEM_SPACE      0
 #define PCIM_BAR_IO_SPACE       1
 
+#if defined(__sparc64__)
+static int screenfd;
+#endif
+
 /**
  * FreeBSD private pci_system structure that extends the base pci_system
  * structure.
@@ -103,12 +114,18 @@
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
 
@@ -118,6 +135,7 @@
 	err = errno;
     }
 
+#if !defined(__sparc64__)
     mrd.mr_base = map->base;
     mrd.mr_len = map->size;
     strncpy(mrd.mr_owner, "pciaccess", sizeof(mrd.mr_owner));
@@ -138,6 +156,7 @@
     }
 
     close(fd);
+#endif
 
     return err;
 }
@@ -146,6 +165,7 @@
 pci_device_freebsd_unmap_range( struct pci_device *dev,
 				struct pci_device_mapping *map )
 {
+#if !defined(__sparc64__)
     struct mem_range_desc mrd;
     struct mem_range_op mro;
     int fd;
@@ -171,6 +191,7 @@
 	    fprintf(stderr, "Failed to open /dev/mem\n");
 	}
     }
+#endif
 
     return pci_device_generic_unmap_range(dev, map);
 }
@@ -293,7 +314,11 @@
     }
 
     printf("Using rom_base = 0x%lx\n", (long)rom_base);
+#if defined(__sparc64__)
+    memfd = screenfd;
+#else
     memfd = open( "/dev/mem", O_RDONLY | O_CLOEXEC );
+#endif
     if ( memfd == -1 )
 	return errno;
 
@@ -306,7 +331,9 @@
     memcpy( buffer, bios, dev->rom_size );
 
     munmap( bios, dev->rom_size );
+#if !defined(__sparc64__)
     close( memfd );
+#endif
 
     if (pci_rom) {
 	pci_device_cfg_write_u32( dev, PCIR_BIOS, rom );
@@ -341,7 +368,6 @@
 static int
 pci_device_freebsd_probe( struct pci_device * dev )
 {
-    struct pci_device_private *priv = (struct pci_device_private *) dev;
     struct pci_bar_io bar;
     uint8_t irq;
     int err, i;
@@ -561,6 +587,154 @@
     freebsd_pci_sys = NULL;
 }
 
+static struct pci_io_handle *
+pci_device_freebsd_open_legacy_io( struct pci_io_handle *ret,
+				   struct pci_device *dev, pciaddr_t base,
+				   pciaddr_t size )
+{
+#if defined(__sparc64__)
+    ret->memory = mmap( NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
+	screenfd, base );
+    if ( ret->memory == MAP_FAILED )
+	return NULL;
+#else
+    ret->fd = open( "/dev/io", O_RDWR | O_CLOEXEC );
+    if ( ret->fd < 0 )
+	return NULL;
+#endif
+    ret->base = base;
+    ret->size = size;
+    return ret;
+}
+
+static void
+pci_device_freebsd_close_io( struct pci_device *dev,
+			     struct pci_io_handle *handle )
+{
+#if !defined(__sparc64__)
+    if ( handle->fd > -1 )
+	close( handle->fd );
+#endif
+}
+
+static uint32_t
+pci_device_freebsd_read32( struct pci_io_handle *handle, uint32_t reg )
+{
+#if defined(__sparc64__)
+    return *(uint32_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inl( handle->base + reg );
+#else
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 4, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
+#endif
+}
+
+static uint16_t
+pci_device_freebsd_read16( struct pci_io_handle *handle, uint32_t reg )
+{
+#if defined(__sparc64__)
+    return *(uint16_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inw( handle->base + reg );
+#else
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 2, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
+#endif
+}
+
+static uint8_t
+pci_device_freebsd_read8( struct pci_io_handle *handle, uint32_t reg )
+{
+#if defined(__sparc64__)
+    return *(uint8_t *)((uintptr_t)handle->memory + reg);
+#elif defined(__i386__) || defined(__amd64__)
+    return inb( handle->base + reg );
+#else
+    struct iodev_pio_req req = { IODEV_PIO_READ, handle->base + reg, 1, 0 };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+    return req.val;
+#endif
+}
+
+static void
+pci_device_freebsd_write32( struct pci_io_handle *handle, uint32_t reg,
+			    uint32_t data )
+{
+#if defined(__sparc64__)
+    *(uint32_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outl( handle->base + reg, data );
+#else
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 4, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+#endif
+}
+
+static void
+pci_device_freebsd_write16( struct pci_io_handle *handle, uint32_t reg,
+			    uint16_t data )
+{
+#if defined(__sparc64__)
+    *(uint16_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outw( handle->base + reg, data );
+#else
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 2, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+#endif
+}
+
+static void
+pci_device_freebsd_write8( struct pci_io_handle *handle, uint32_t reg,
+			   uint8_t data )
+{
+#if defined(__sparc64__)
+    *(uint8_t *)((uintptr_t)handle->memory + reg) = data;
+#elif defined(__i386__) || defined(__amd64__)
+    outb(handle->base + reg, data);
+#else
+    struct iodev_pio_req req = { IODEV_PIO_WRITE, handle->base + reg, 1, data };
+    if ( handle->fd > -1 )
+	ioctl( handle->fd, IODEV_PIO, &req );
+#endif
+}
+
+static int
+pci_device_freebsd_map_legacy( struct pci_device *dev, pciaddr_t base,
+			       pciaddr_t size, unsigned map_flags, void **addr )
+{
+    struct pci_device_mapping map;
+    int err;
+
+    map.base = base;
+    map.size = size;
+    map.flags = map_flags;
+    map.memory = NULL;
+    err = pci_device_freebsd_map_range( dev, &map );
+    *addr = map.memory;
+    return err;
+}
+
+static int
+pci_device_freebsd_unmap_legacy( struct pci_device *dev, void *addr,
+				 pciaddr_t size)
+{
+    struct pci_device_mapping map;
+
+    map.memory = addr;
+    map.size = size;
+    map.flags = 0;
+    return pci_device_freebsd_unmap_range( dev, &map );
+}
+
 static const struct pci_system_methods freebsd_pci_methods = {
     .destroy = pci_system_freebsd_destroy,
     .destroy_device = NULL, /* nothing to do for this */
@@ -571,6 +745,16 @@
     .read = pci_device_freebsd_read,
     .write = pci_device_freebsd_write,
     .fill_capabilities = pci_fill_capabilities_generic,
+    .open_legacy_io = pci_device_freebsd_open_legacy_io,
+    .close_io = pci_device_freebsd_close_io,
+    .read32 = pci_device_freebsd_read32,
+    .read16 = pci_device_freebsd_read16,
+    .read8 = pci_device_freebsd_read8,
+    .write32 = pci_device_freebsd_write32,
+    .write16 = pci_device_freebsd_write16,
+    .write8 = pci_device_freebsd_write8,
+    .map_legacy = pci_device_freebsd_map_legacy,
+    .unmap_legacy = pci_device_freebsd_unmap_legacy,
 };
 
 /**
@@ -644,3 +828,11 @@
 
     return 0;
 }
+
+void
+pci_system_freebsd_init_dev_mem(int fd)
+{
+#if defined(__sparc64__)
+    screenfd = fd;
+#endif
+}
