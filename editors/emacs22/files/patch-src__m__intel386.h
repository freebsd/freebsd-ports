--- src/m/intel386.h.orig	2008-02-28 00:32:04.000000000 +0100
+++ src/m/intel386.h	2013-09-14 16:14:18.000000000 +0200
@@ -58,7 +58,7 @@ NOTE-END */
 /* Define NO_ARG_ARRAY if you cannot take the address of the first of a
  * group of arguments and treat it as an array of the arguments.  */
 
-/* #define NO_ARG_ARRAY */
+#define NO_ARG_ARRAY
 
 /* Define WORD_MACHINE if addresses and such have
  * to be corrected before they can be used as byte counts.  */
