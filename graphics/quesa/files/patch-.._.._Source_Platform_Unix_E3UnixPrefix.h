--- ../../Source/Platform/Unix/E3UnixPrefix.h.orig	Wed Feb  4 10:52:24 2004
+++ ../../Source/Platform/Unix/E3UnixPrefix.h	Wed Feb  4 10:52:51 2004
@@ -44,7 +44,9 @@
 //-----------------------------------------------------------------------------
 // Build constants go here
 
-
+#ifdef __FreeBSD__
+#define isfinite finite
+#endif
 
 
 
