--- src/uni.h.orig	2008-07-31 15:22:38.000000000 +0400
+++ src/uni.h	2013-03-04 02:09:01.580934046 +0400
@@ -1,6 +1,7 @@
 #ifndef UNI
 #define UNI
 #include <iostream>
+#include <stdint.h>
 
 struct Options
 	{
@@ -15,6 +16,7 @@
 //#define DEBUG
 //#define CVS
 
+#undef __WORDSIZE
 
 #ifdef __WORDSIZE
 #else
