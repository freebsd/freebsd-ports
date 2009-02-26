--- src/freebsd_pci.c.orig	2009-02-25 19:30:48.000000000 -0600
+++ src/freebsd_pci.c	2009-02-25 19:30:58.000000000 -0600
@@ -53,6 +53,25 @@
 #define	PCIS_DISPLAY_3D		0x02
 #define	PCIS_DISPLAY_OTHER	0x80
 
+/* Registers taken from pcireg.h */
+#define PCIR_COMMAND    0x04
+#define PCIM_CMD_PORTEN         0x0001
+#define PCIM_CMD_MEMEN          0x0002
+#define PCIR_BIOS	0x30
+#define PCIM_BIOS_ENABLE	0x01
+#define PCIM_BIOS_ADDR_MASK	0xfffff800
+
+#define PCIR_BARS       0x10
+#define PCIR_BAR(x)             (PCIR_BARS + (x) * 4)
+#define PCI_BAR_IO(x)           (((x) & PCIM_BAR_SPACE) == PCIM_BAR_IO_SPACE)
+#define PCI_BAR_MEM(x)          (((x) & PCIM_BAR_SPACE) == PCIM_BAR_MEM_SPACE)
+#define PCIM_BAR_MEM_TYPE       0x00000006
+#define PCIM_BAR_MEM_64         4
+#define PCIM_BAR_MEM_PREFETCH   0x00000008
+#define PCIM_BAR_SPACE          0x00000001
+#define PCIM_BAR_MEM_SPACE      0
+#define PCIM_BAR_IO_SPACE       1
+
 /**
  * FreeBSD private pci_system structure that extends the base pci_system
  * structure.
@@ -214,6 +233,10 @@
     while ( size > 0 ) {
 	int towrite = (size < 4 ? size : 4);
 
+	/* Only power of two allowed. */
+	if (towrite == 3)
+	    towrite = 2;
+
 	io.pi_reg = offset;
 	io.pi_width = towrite;
 	memcpy( &io.pi_data, data, towrite );
@@ -239,8 +262,12 @@
 static int
 pci_device_freebsd_read_rom( struct pci_device * dev, void * buffer )
 {
+    struct pci_device_private *priv = (struct pci_device_private *) dev;
     void *bios;
-    int memfd;
+    pciaddr_t rom_base;
+    uint32_t rom;
+    uint16_t reg;
+    int pci_rom, memfd;
 
     if ( ( dev->device_class & 0x00ffff00 ) !=
 	 ( ( PCIC_DISPLAY << 16 ) | ( PCIS_DISPLAY_VGA << 8 ) ) )
@@ -248,11 +275,29 @@
 	return ENOSYS;
     }
 
+    if (priv->rom_base == 0) {
+#if defined(__amd64__) || defined(__i386__)
+	rom_base = 0xc0000;
+	pci_rom = 0;
+#else
+	return ENOSYS;
+#endif
+    } else {
+	rom_base = priv->rom_base;
+	pci_rom = 1;
+
+	pci_device_cfg_read_u16( dev, &reg, PCIR_COMMAND );
+	pci_device_cfg_write_u16( dev, reg | PCIM_CMD_MEMEN, PCIR_COMMAND );
+	pci_device_cfg_read_u32( dev, &rom, PCIR_BIOS );
+	pci_device_cfg_write_u32( dev, rom | PCIM_BIOS_ENABLE, PCIR_BIOS );
+    }
+
+    printf("Using rom_base = 0x%lx\n", (long)rom_base);
     memfd = open( "/dev/mem", O_RDONLY );
     if ( memfd == -1 )
 	return errno;
 
-    bios = mmap( NULL, dev->rom_size, PROT_READ, 0, memfd, 0xc0000 );
+    bios = mmap( NULL, dev->rom_size, PROT_READ, 0, memfd, rom_base );
     if ( bios == MAP_FAILED ) {
 	close( memfd );
 	return errno;
@@ -263,6 +308,11 @@
     munmap( bios, dev->rom_size );
     close( memfd );
 
+    if (pci_rom) {
+	pci_device_cfg_write_u32( dev, PCIR_BIOS, rom );
+	pci_device_cfg_write_u16( dev, PCIR_COMMAND, reg );
+    }
+
     return 0;
 }
 
@@ -273,7 +323,7 @@
 {
     struct pci_device_private *priv = (struct pci_device_private *) dev;
 
-    switch (priv->header_type & 0x7f) {
+    switch (priv->header_type) {
     case 0:
 	return 6;
     case 1:
@@ -286,6 +336,64 @@
     }
 }
 
+#ifdef PCIOCGETBAR
+
+static int
+pci_device_freebsd_probe( struct pci_device * dev )
+{
+    struct pci_device_private *priv = (struct pci_device_private *) dev;
+    struct pci_bar_io bar;
+    uint8_t irq;
+    int err, i;
+
+#if HAVE_PCI_IO_PC_DOMAIN
+    bar.pbi_sel.pc_domain = dev->domain;
+#endif
+    bar.pbi_sel.pc_bus = dev->bus;
+    bar.pbi_sel.pc_dev = dev->dev;
+    bar.pbi_sel.pc_func = dev->func;
+
+
+    /* Many of the fields were filled in during initial device enumeration.
+     * At this point, we need to fill in regions, rom_size, and irq.
+     */
+
+    err = pci_device_cfg_read_u8( dev, &irq, 60 );
+    if (err)
+	return errno;
+    dev->irq = irq;
+
+    for (i = 0; i < pci_device_freebsd_get_num_regions( dev ); i++) {
+	bar.pbi_reg = PCIR_BAR(i);
+	if ( ioctl( freebsd_pci_sys->pcidev, PCIOCGETBAR, &bar ) < 0 ) 
+	    continue;
+
+	if (PCI_BAR_IO(bar.pbi_base))
+	    dev->regions[i].is_IO = 1;
+
+	if ((bar.pbi_base & PCIM_BAR_MEM_TYPE) == PCIM_BAR_MEM_64)
+	    dev->regions[i].is_64 = 1;
+
+	if (bar.pbi_base & PCIM_BAR_MEM_PREFETCH)
+	    dev->regions[i].is_prefetchable = 1;
+
+	dev->regions[i].base_addr = bar.pbi_base & ~((uint64_t)0xf);
+	dev->regions[i].size = bar.pbi_length;
+    }
+
+    /* If it's a VGA device, set up the rom size for read_rom using the
+     * 0xc0000 mapping.
+     */
+     if ((dev->device_class & 0x00ffff00) ==
+	((PCIC_DISPLAY << 16) | (PCIS_DISPLAY_VGA << 8))) {
+	     dev->rom_size = 64 * 1024;
+     }
+
+     return 0;
+}
+
+#else
+
 /** Masks out the flag bigs of the base address register value */
 static uint32_t
 get_map_base( uint32_t val )
@@ -300,20 +408,13 @@
 static int
 get_test_val_size( uint32_t testval )
 {
-    int size = 1;
-
     if (testval == 0)
 	return 0;
 
     /* Mask out the flag bits */
     testval = get_map_base( testval );
 
-    while ((testval & 1) == 0) {
-	size <<= 1;
-	testval >>= 1;
-    }
-
-    return size;
+    return 1 << (ffs(testval) - 1);
 }
 
 /**
@@ -329,6 +430,7 @@
 				    int bar )
 {
     uint32_t addr, testval;
+    uint16_t cmd;
     int err;
 
     /* Get the base address */
@@ -336,12 +438,35 @@
     if (err != 0)
 	return err;
 
+    /*
+     * We are going to be doing evil things to the registers here
+     * so disable them via the command register first. 
+     */
+    err = pci_device_cfg_read_u16( dev, &cmd, PCIR_COMMAND );
+    if (err != 0)
+	return err;
+
+    err = pci_device_cfg_write_u16( dev,
+	cmd & ~(PCI_BAR_MEM(addr) ? PCIM_CMD_MEMEN : PCIM_CMD_PORTEN),
+	PCIR_COMMAND );
+    if (err != 0)
+	return err;
+
     /* Test write all ones to the register, then restore it. */
     err = pci_device_cfg_write_u32( dev, 0xffffffff, bar );
     if (err != 0)
 	return err;
-    pci_device_cfg_read_u32( dev, &testval, bar );
+    err = pci_device_cfg_read_u32( dev, &testval, bar );
+    if (err != 0)
+	return err;
     err = pci_device_cfg_write_u32( dev, addr, bar );
+    if (err != 0)
+	return err;
+
+    /* Restore the command register */
+    err = pci_device_cfg_write_u16( dev, cmd, PCIR_COMMAND );
+    if (err != 0)
+	return err;
 
     if (addr & 0x01)
 	dev->regions[region].is_IO = 1;
@@ -352,6 +477,7 @@
 
     /* Set the size */
     dev->regions[region].size = get_test_val_size( testval );
+	printf("size = 0x%lx\n", (long)dev->regions[region].size);
 
     /* Set the base address value */
     if (dev->regions[region].is_64) {
@@ -374,6 +500,7 @@
 pci_device_freebsd_probe( struct pci_device * dev )
 {
     struct pci_device_private *priv = (struct pci_device_private *) dev;
+    uint32_t reg, size;
     uint8_t irq;
     int err, i, bar;
 
@@ -386,10 +513,6 @@
 	return errno;
     dev->irq = irq;
 
-    err = pci_device_cfg_read_u8( dev, &priv->header_type, 0x0e );
-    if (err)
-	return errno;
-
     bar = 0x10;
     for (i = 0; i < pci_device_freebsd_get_num_regions( dev ); i++) {
 	pci_device_freebsd_get_region_info( dev, i, bar );
@@ -400,18 +523,36 @@
 	    bar += 0x04;
     }
 
-    /* If it's a VGA device, set up the rom size for read_rom using the
-     * 0xc0000 mapping.
-     */
+    /* If it's a VGA device, set up the rom size for read_rom */
     if ((dev->device_class & 0x00ffff00) ==
 	((PCIC_DISPLAY << 16) | (PCIS_DISPLAY_VGA << 8)))
     {
-	dev->rom_size = 64 * 1024;
+	err = pci_device_cfg_read_u32( dev, &reg, PCIR_BIOS );
+	if (err)
+	    return errno;
+
+	if (reg == 0) {
+	    dev->rom_size = 0x10000;
+	    return 0;
+	}
+
+	err = pci_device_cfg_write_u32( dev, ~PCIM_BIOS_ENABLE, PCIR_BIOS );
+	if (err)
+	    return errno;
+	pci_device_cfg_read_u32( dev, &size, PCIR_BIOS );
+	pci_device_cfg_write_u32( dev, reg, PCIR_BIOS );
+
+	if ((reg & PCIM_BIOS_ADDR_MASK) != 0) {
+	    priv->rom_base = (reg & PCIM_BIOS_ADDR_MASK);
+	    dev->rom_size = -(size & PCIM_BIOS_ADDR_MASK);
+	}
     }
 
     return 0;
 }
 
+#endif
+
 static void
 pci_system_freebsd_destroy(void)
 {
@@ -495,8 +636,10 @@
 	pci_sys->devices[ i ].base.device_id = p->pc_device;
 	pci_sys->devices[ i ].base.subvendor_id = p->pc_subvendor;
 	pci_sys->devices[ i ].base.subdevice_id = p->pc_subdevice;
+	pci_sys->devices[ i ].base.revision = p->pc_revid;
 	pci_sys->devices[ i ].base.device_class = (uint32_t)p->pc_class << 16 |
 	    (uint32_t)p->pc_subclass << 8 | (uint32_t)p->pc_progif;
+	pci_sys->devices[ i ].header_type = p->pc_hdr & 0x7f;
     }
 
     return 0;
