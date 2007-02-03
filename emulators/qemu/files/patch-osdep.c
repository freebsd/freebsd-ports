Index: qemu/osdep.c
@@ -79,7 +79,9 @@
 
 #if defined(USE_KQEMU)
 
+#ifndef __FreeBSD__
 #include <sys/vfs.h>
+#endif
 #include <sys/mman.h>
 #include <fcntl.h>
 
@@ -90,6 +92,7 @@
     const char *tmpdir;
     char phys_ram_file[1024];
     void *ptr;
+#ifndef __FreeBSD__
 #ifdef HOST_SOLARIS
     struct statvfs stfs;
 #else
@@ -151,12 +154,20 @@
         }
         unlink(phys_ram_file);
     }
+#endif
     size = (size + 4095) & ~4095;
+#ifndef __FreeBSD__
     ftruncate(phys_ram_fd, phys_ram_size + size);
     ptr = mmap(NULL, 
                size, 
                PROT_WRITE | PROT_READ, MAP_SHARED, 
                phys_ram_fd, phys_ram_size);
+#else
+    ptr = mmap(NULL, 
+               size, 
+               PROT_WRITE | PROT_READ, MAP_PRIVATE|MAP_ANON, 
+               -1, 0);
+#endif
     if (ptr == MAP_FAILED) {
         fprintf(stderr, "Could not map physical memory\n");
         exit(1);
