--- src/freebsd_pci.c.orig	2009-01-25 11:53:11.000000000 -0500
+++ src/freebsd_pci.c	2009-01-25 11:53:26.000000000 -0500
@@ -53,6 +53,17 @@
 #define	PCIS_DISPLAY_3D		0x02
 #define	PCIS_DISPLAY_OTHER	0x80
 
+/* Registers taken from pcireg.h */
+#define PCIR_COMMAND    0x04
+#define PCIM_CMD_PORTEN         0x0001
+#define PCIM_CMD_MEMEN          0x0002
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
@@ -214,6 +225,10 @@
     while ( size > 0 ) {
 	int towrite = (size < 4 ? size : 4);
 
+	/* Only power of two allowed. */
+	if (towrite == 3)
+	    towrite = 2;
+
 	io.pi_reg = offset;
 	io.pi_width = towrite;
 	memcpy( &io.pi_data, data, towrite );
@@ -300,20 +315,13 @@
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
@@ -329,6 +337,7 @@
 				    int bar )
 {
     uint32_t addr, testval;
+    uint16_t cmd;
     int err;
 
     /* Get the base address */
@@ -336,12 +345,35 @@
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
