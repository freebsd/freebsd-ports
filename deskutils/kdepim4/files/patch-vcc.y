--- libical/src/libicalvcal/vcc.y	Mon Jan  1 16:49:58 2001
+++ libical/src/libicalvcal/vcc.y.new	Sun Jun  2 12:42:57 2002
@@ -107,7 +107,7 @@
 #endif
 
 #include <string.h>
-#ifndef __MWERKS__
+#if !defined(__MWERKS__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include <stdio.h>
