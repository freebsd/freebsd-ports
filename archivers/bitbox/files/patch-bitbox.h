--- bitbox.h.orig	Mon Apr  9 01:38:16 2001
+++ bitbox.h	Mon Apr  9 01:38:29 2001
@@ -1,7 +1,7 @@
 #ifndef __bitbox__
 #define __bitbox__
 
-#include <stdint.h>
+/* #include <stdint.h> */
 
 /* Serialization/deserialization macros, just to save a few keystrokes.  Notice
    that they all assume an int named rc is in scope, and that they're sensitive 
