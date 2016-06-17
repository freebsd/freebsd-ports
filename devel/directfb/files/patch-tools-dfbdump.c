--- tools/dfbdump.c.orig	2012-05-23 13:43:12 UTC
+++ tools/dfbdump.c
@@ -68,6 +68,8 @@
 #include <core/windows_internal.h>
 #include <core/wm.h>
 
+typedef unsigned long ulong;
+
 static DirectFBPixelFormatNames( format_names );
 
 /**********************************************************************************************************************/
