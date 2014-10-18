--- galerautils/src/gu_mmap.cpp.orig	2014-10-15 11:08:26.000000000 -0400
+++ galerautils/src/gu_mmap.cpp	2014-10-15 11:09:06.000000000 -0400
@@ -21,7 +21,7 @@
         :
         size   (fd.size()),
         ptr    (mmap (NULL, size, PROT_READ|PROT_WRITE,
-                      MAP_SHARED|MAP_NORESERVE, fd.get(), 0)),
+                      MAP_SHARED, fd.get(), 0)),
         mapped (ptr != GU_MAP_FAILED)
     {
         if (!mapped)
