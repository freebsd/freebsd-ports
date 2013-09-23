--- src/m/intel386.h.orig	1997-08-30 09:18:39.000000000 +0200
+++ src/m/intel386.h	2013-09-14 16:52:48.000000000 +0200
@@ -57,7 +57,7 @@
 /* Define NO_ARG_ARRAY if you cannot take the address of the first of a
  * group of arguments and treat it as an array of the arguments.  */
 
-/* #define NO_ARG_ARRAY */
+#define NO_ARG_ARRAY
 
 /* Define WORD_MACHINE if addresses and such have
  * to be corrected before they can be used as byte counts.  */
