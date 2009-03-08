Index: qemu/vl.c
@@ -75,6 +75,7 @@
 #include <sys/stat.h>
 #ifdef __FreeBSD__
 #include <libutil.h>
+#include <sys/param.h>
 #else
 #include <util.h>
 #endif
@@ -9850,15 +9850,15 @@
         phys_ram_size += ram_size;
     }
 
+    /* init the dynamic translator */
+    cpu_exec_init_all(tb_size * 1024 * 1024);
+
     phys_ram_base = qemu_vmalloc(phys_ram_size);
     if (!phys_ram_base) {
         fprintf(stderr, "Could not allocate physical memory\n");
         exit(1);
     }
 
-    /* init the dynamic translator */
-    cpu_exec_init_all(tb_size * 1024 * 1024);
-
     bdrv_init();
 
     /* we always create the cdrom drive, even if no disk is there */
