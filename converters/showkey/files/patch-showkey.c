--- showkey.c.orig	2012-03-03 16:44:46 UTC
+++ showkey.c
@@ -11,6 +11,7 @@
 #include <string.h>
 #include <stdbool.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #define ALT	0x80
 #define ESC	0x1b
@@ -80,7 +81,7 @@ static void visualize(int c, /*@out@*/ch
 }
 
 
-main()
+int main()
 {
     struct termios	cooked, raw;
     unsigned char	c;
