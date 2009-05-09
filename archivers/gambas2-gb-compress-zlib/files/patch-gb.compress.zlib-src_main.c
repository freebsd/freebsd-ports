--- gb.compress.zlib/src/main.c	2009-03-20 05:44:31.000000000 -0500
+++ gb.compress.zlib/src/main.c	2009-05-03 13:17:25.000000000 -0500
@@ -24,13 +24,9 @@
 
 #define __MAIN_C
 
-#include <bits/wordsize.h>
-
 // Use 64 bits I/O
 #define _FILE_OFFSET_BITS 64
-#if __WORDSIZE == 64
 #define _LARGEFILE64_SOURCE
-#endif
 
 #include <errno.h>
 #include <stdio.h>
