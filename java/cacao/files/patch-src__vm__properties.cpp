--- src/vm/properties.cpp.orig	2012-09-03 12:10:00.000000000 -0400
+++ src/vm/properties.cpp	2012-10-04 14:34:15.000000000 -0400
@@ -74,7 +74,11 @@
 
 	p = MNEW(char, 4096);
 
+#if defined(__FreeBSD__)
+	if (os::readlink("/proc/curproc/file", p, 4095) == -1)
+#else
 	if (os::readlink("/proc/self/exe", p, 4095) == -1)
+#endif
 		os::abort_errno("readlink failed");
 
 	/* We have a path like:
