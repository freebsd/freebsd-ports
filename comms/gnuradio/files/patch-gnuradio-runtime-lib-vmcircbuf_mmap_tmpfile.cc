Use MAP_FIXED flag to ensure buffer halves are contiguous

(backport of ca44241)

--- gnuradio-runtime/lib/vmcircbuf_mmap_tmpfile.cc.orig	2021-09-30 14:10:55 UTC
+++ gnuradio-runtime/lib/vmcircbuf_mmap_tmpfile.cc
@@ -107,19 +107,11 @@ vmcircbuf_mmap_tmpfile::vmcircbuf_mmap_tmpfile(int siz
         throw std::runtime_error("gr::vmcircbuf_mmap_tmpfile");
     }
 
-    // unmap the 2nd half
-    if (munmap((char*)first_copy + size, size) == -1) {
-        close(seg_fd); // cleanup
-        perror("gr::vmcircbuf_mmap_tmpfile: munmap (1)");
-        throw std::runtime_error("gr::vmcircbuf_mmap_tmpfile");
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
                              seg_fd,
                              (off_t)0);
 
@@ -127,15 +119,6 @@ vmcircbuf_mmap_tmpfile::vmcircbuf_mmap_tmpfile(int siz
         munmap(first_copy, size); // cleanup
         close(seg_fd);
         perror("gr::vmcircbuf_mmap_tmpfile: mmap(2)");
-        throw std::runtime_error("gr::vmcircbuf_mmap_tmpfile");
-    }
-
-    // check for contiguity
-    if ((char*)second_copy != (char*)first_copy + size) {
-        munmap(first_copy, size); // cleanup
-        munmap(second_copy, size);
-        close(seg_fd);
-        perror("gr::vmcircbuf_mmap_tmpfile: non-contiguous second copy");
         throw std::runtime_error("gr::vmcircbuf_mmap_tmpfile");
     }
 
