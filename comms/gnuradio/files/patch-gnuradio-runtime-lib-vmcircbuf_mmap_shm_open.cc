Use MAP_FIXED flag to ensure buffer halves are contiguous

(backport of ca44241)

--- gnuradio-runtime/lib/vmcircbuf_mmap_shm_open.cc.orig	2021-09-30 14:10:55 UTC
+++ gnuradio-runtime/lib/vmcircbuf_mmap_shm_open.cc
@@ -122,19 +122,11 @@ vmcircbuf_mmap_shm_open::vmcircbuf_mmap_shm_open(int s
         throw std::runtime_error("gr::vmcircbuf_mmap_shm_open");
     }
 
-    // unmap the 2nd half
-    if (munmap((char*)first_copy + size, size) == -1) {
-        close(shm_fd); // cleanup
-        perror("gr::vmcircbuf_mmap_shm_open: munmap (1)");
-        throw std::runtime_error("gr::vmcircbuf_mmap_shm_open");
-    }
-
-    // map the first half into the now available hole where the
-    // second half used to be.
+    // map the first half into the second half of the address space.
     void* second_copy = mmap((char*)first_copy + size,
                              size,
                              PROT_READ | PROT_WRITE,
-                             MAP_SHARED,
+                             MAP_SHARED | MAP_FIXED,
                              shm_fd,
                              (off_t)0);
 
