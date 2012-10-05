--- src/cacao/cacao.cpp.orig	2012-09-03 12:10:00.000000000 -0400
+++ src/cacao/cacao.cpp	2012-10-04 14:34:51.000000000 -0400
@@ -90,7 +90,11 @@
 
 	path = (char*) os::malloc(sizeof(char) * 4096);
 
+#  if defined(__FreeBSD__)
+	if (readlink("/proc/curproc/file", path, 4095) == -1) {
+#  else
 	if (readlink("/proc/self/exe", path, 4095) == -1) {
+#  endif
 		fprintf(stderr, "main: readlink failed: %s\n", strerror(errno));
 		os::abort();
 	}
