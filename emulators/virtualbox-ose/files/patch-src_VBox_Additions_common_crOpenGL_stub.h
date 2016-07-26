--- src/VBox/Additions/common/crOpenGL/stub.h.orig	2016-07-18 11:50:44 UTC
+++ src/VBox/Additions/common/crOpenGL/stub.h
@@ -47,7 +47,7 @@
 #include <X11/extensions/Xfixes.h>
 #endif
 
-#if defined(WINDOWS) || defined(Linux) || defined(SunOS)
+#if defined(WINDOWS) || defined(Linux) || defined(FreeBSD) || defined(SunOS)
 # define CR_NEWWINTRACK
 #endif
 
