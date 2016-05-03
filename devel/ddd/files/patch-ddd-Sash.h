--- ddd/Sash.h.orig	2009-02-11 18:25:06.000000000 +0100
+++ ddd/Sash.h	2016-04-04 21:29:40.084679000 +0200
@@ -29,11 +29,7 @@
 #define _DDD_Sash_h
 
 extern "C" {
-#define new new_w
-#define class class_w
 #include <Xm/SashP.h>		// XmIsSash()
-#undef class
-#undef new
 }
 
 #endif // _DDD_Sash_h
