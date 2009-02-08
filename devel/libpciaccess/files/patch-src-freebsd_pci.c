--- src/freebsd_pci.c.orig	2008-10-31 11:40:09.000000000 -0400
+++ src/freebsd_pci.c	2009-02-08 18:03:29.000000000 -0500
@@ -53,6 +53,20 @@
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
+#define PCI_BAR_IO(x)           (((x) & PCIM_BAR_SPACE) == PCIM_BAR_IO_SPACE)
+#define PCI_BAR_MEM(x)          (((x) & PCIM_BAR_SPACE) == PCIM_BAR_MEM_SPACE)
+#define PCIM_BAR_SPACE          0x00000001
+#define PCIM_BAR_MEM_SPACE      0
+#define PCIM_BAR_IO_SPACE       1
+
 /**
  * FreeBSD private pci_system structure that extends the base pci_system
  * structure.
@@ -214,6 +228,10 @@
     while ( size > 0 ) {
 	int towrite = (size < 4 ? size : 4);
 
+	/* Only power of two allowed. */
+	if (towrite == 3)
+	    towrite = 2;
+
 	io.pi_reg = offset;
 	io.pi_width = towrite;
 	memcpy( &io.pi_data, data, towrite );
@@ -239,8 +257,12 @@
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
@@ -248,11 +270,29 @@
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
@@ -263,6 +303,11 @@
     munmap( bios, dev->rom_size );
     close( memfd );
 
+    if (pci_rom) {
+	pci_device_cfg_write_u32( dev, PCIR_BIOS, rom );
+	pci_device_cfg_write_u16( dev, PCIR_COMMAND, reg );
+    }
+
     return 0;
 }
 
@@ -300,20 +345,13 @@
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
@@ -329,6 +367,7 @@
 				    int bar )
 {
     uint32_t addr, testval;
+    uint16_t cmd;
     int err;
 
     /* Get the base address */
@@ -336,12 +375,35 @@
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
@@ -352,6 +414,7 @@
 
     /* Set the size */
     dev->regions[region].size = get_test_val_size( testval );
+	printf("size = 0x%lx\n", (long)dev->regions[region].size);
 
     /* Set the base address value */
     if (dev->regions[region].is_64) {
@@ -374,6 +437,7 @@
 pci_device_freebsd_probe( struct pci_device * dev )
 {
     struct pci_device_private *priv = (struct pci_device_private *) dev;
+    uint32_t reg, size;
     uint8_t irq;
     int err, i, bar;
 
@@ -400,13 +464,29 @@
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
@@ -495,6 +575,7 @@
 	pci_sys->devices[ i ].base.device_id = p->pc_device;
 	pci_sys->devices[ i ].base.subvendor_id = p->pc_subvendor;
 	pci_sys->devices[ i ].base.subdevice_id = p->pc_subdevice;
+	pci_sys->devices[ i ].base.revision = p->pc_revid;
 	pci_sys->devices[ i ].base.device_class = (uint32_t)p->pc_class << 16 |
 	    (uint32_t)p->pc_subclass << 8 | (uint32_t)p->pc_progif;
     }
