--- src/freebsd_pci.c.orig	2009-05-07 10:35:59.000000000 -0500
+++ src/freebsd_pci.c	2009-05-07 10:36:10.000000000 -0500
@@ -72,6 +72,10 @@
 #define PCIM_BAR_MEM_SPACE      0
 #define PCIM_BAR_IO_SPACE       1
 
+#if defined(__sparc64__)
+static int screenfd;
+#endif
+
 /**
  * FreeBSD private pci_system structure that extends the base pci_system
  * structure.
@@ -103,12 +107,18 @@
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
     fd = open("/dev/mem", O_RDWR);
+#endif
     if (fd == -1)
 	return errno;
 
@@ -118,6 +128,7 @@
 	err = errno;
     }
 
+#if !defined(__sparc64__)
     mrd.mr_base = map->base;
     mrd.mr_len = map->size;
     strncpy(mrd.mr_owner, "pciaccess", sizeof(mrd.mr_owner));
@@ -138,6 +149,7 @@
     }
 
     close(fd);
+#endif
 
     return err;
 }
@@ -146,6 +158,7 @@
 pci_device_freebsd_unmap_range( struct pci_device *dev,
 				struct pci_device_mapping *map )
 {
+#if defined(__sparc64__)
     struct mem_range_desc mrd;
     struct mem_range_op mro;
     int fd;
@@ -171,6 +184,7 @@
 	    fprintf(stderr, "Failed to open /dev/mem\n");
 	}
     }
+#endif
 
     return pci_device_generic_unmap_range(dev, map);
 }
@@ -293,20 +307,28 @@
     }
 
     printf("Using rom_base = 0x%lx\n", (long)rom_base);
+#if defined(__sparc64__)
+    memfd = screenfd;
+#else
     memfd = open( "/dev/mem", O_RDONLY );
+#endif
     if ( memfd == -1 )
 	return errno;
 
     bios = mmap( NULL, dev->rom_size, PROT_READ, 0, memfd, rom_base );
     if ( bios == MAP_FAILED ) {
+#if !defined(__sparc64__)
 	close( memfd );
+#endif
 	return errno;
     }
 
     memcpy( buffer, bios, dev->rom_size );
 
     munmap( bios, dev->rom_size );
+#if !defined(__sparc64__)
     close( memfd );
+#endif
 
     if (pci_rom) {
 	pci_device_cfg_write_u32( dev, PCIR_BIOS, rom );
@@ -341,7 +363,6 @@
 static int
 pci_device_freebsd_probe( struct pci_device * dev )
 {
-    struct pci_device_private *priv = (struct pci_device_private *) dev;
     struct pci_bar_io bar;
     uint8_t irq;
     int err, i;
@@ -644,3 +665,11 @@
 
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
