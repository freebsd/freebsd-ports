--- src/core/pcmanx_utils.h.orig	2010-10-12 21:10:55.000000000 +0800
+++ src/core/pcmanx_utils.h	2010-10-12 21:11:00.000000000 +0800
@@ -5,7 +5,6 @@
 #include <config.h>
 #endif
 
-#include <bits/wordsize.h>
 #if __WORDSIZE == 64
 typedef unsigned long int word_t;
 #else
