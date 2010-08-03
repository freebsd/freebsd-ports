--- mozilla/config/mkdepend/imakemdep.h.orig	2009-12-05 15:43:09.000000000 +0100
+++ mozilla/config/mkdepend/imakemdep.h	2009-12-05 15:44:00.000000000 +0100
@@ -277,8 +277,8 @@
 # ifdef __i386__
 	"-D__i386__",
 # endif
-# ifdef __x86_64__
-	"-D__x86_64__",
+# ifdef defined(__amd64__) || defined(__x86_64__)
+	"-D__amd64__ -D__x86_64__",
 # endif
 # ifdef __GNUC__
 	"-traditional",
