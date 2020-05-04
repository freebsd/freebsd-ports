--- lib/openfile.cpp.orig	2015-12-25 14:22:43 UTC
+++ lib/openfile.cpp
@@ -53,7 +53,7 @@ int openfile(const char* fname) {
   if (!pbase) {
     pbase = mmap((caddr_t)0, st.st_size, PROT_READ, MAP_PRIVATE, fildes, 0);
     onmemory = 0;
-    if (pbase < 0) {
+    if (pbase == MAP_FAILED) {
       /* mmap failed */
       fprintf(stderr, "ERR: failed to execute mmap.\n");
       return -1;
