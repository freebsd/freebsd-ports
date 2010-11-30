--- tools/rpmdigest.c.orig	2009-01-16 21:47:11.000000000 +0100
+++ tools/rpmdigest.c	2010-09-13 21:30:57.000000000 +0200
@@ -887,7 +887,7 @@
 When checking, the input should be a former output of this program.  The\n\
 default mode is to print a line with digest, a character indicating type\n\
 (`*' for binary, ` ' for text), and name for each FILE.\n\
-"), NULL },
+\0"), NULL }, /* embed NUL to work around expandMacro bug in Doxygen 1.7.1 */
 
   POPT_TABLEEND
 };
