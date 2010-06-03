--- tools/dfbdump.c
+++ tools/dfbdump.c
@@ -66,6 +66,8 @@
 #include <core/windows_internal.h>
 #include <core/wm.h>
 
+typedef unsigned long ulong;
+
 static DirectFBPixelFormatNames( format_names );
 
 /**********************************************************************************************************************/
