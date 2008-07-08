Index: qemu/osdep.c
@@ -68,7 +68,9 @@
 
 #if defined(USE_KQEMU)
 
+#ifndef __FreeBSD__
 #include <sys/vfs.h>
+#endif
 #include <sys/mman.h>
 #include <fcntl.h>
 
@@ -79,6 +81,7 @@
     const char *tmpdir;
     char phys_ram_file[1024];
     void *ptr;
+#ifndef __FreeBSD__
 #ifdef HOST_SOLARIS
     struct statvfs stfs;
 #else
@@ -138,7 +141,9 @@
         }
         unlink(phys_ram_file);
     }
+#endif
     size = (size + 4095) & ~4095;
+#ifndef __FreeBSD__
     ftruncate(phys_ram_fd, phys_ram_size + size);
     ptr = mmap(NULL,
                size,
@@ -148,6 +153,13 @@
         fprintf(stderr, "Could not map physical memory\n");
         exit(1);
     }
+#else
+    ptr = malloc(size);
+    if (ptr == NULL) {
+        fprintf(stderr, "Could not allocate physical memory\n");
+        exit(1);
+    }
+#endif
     phys_ram_size += size;
     return ptr;
 }
