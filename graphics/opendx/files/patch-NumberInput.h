--- src/uipp/widgets/NumberInput.h.orig	Wed Mar 12 22:56:49 2003
+++ src/uipp/widgets/NumberInput.h	Wed Mar 12 23:06:33 2003
@@ -12,7 +12,7 @@
 #include <stdlib.h>	/*  strtod()  */
 #include <errno.h>	/*  errno, ERANGE  */
 #define XK_MISCELLANY 1
-#include <X11/keysymdef.h>
+#include <X11/keysym.h>
 
 #if defined(__cplusplus) || defined(c_plusplus)
 extern "C" {
