--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/SYSTEM_.c	Tue Feb 15 14:26:45 1994
+++ ./reuse/m2c/SYSTEM_.c	Thu Aug  5 18:49:33 2004
@@ -1,6 +1,7 @@
 /* $Id: SYSTEM_.c,v 1.4 1991/11/21 16:57:59 grosch rel grosch $ */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "SYSTEM_.h"
 
@@ -49,7 +50,9 @@
 (lo, hi) register CARDINAL lo, hi;
 # endif
 {
-    return (lo <= hi ? ~0X0L >> lo << lo + SYSTEM_MaxSet - hi >> SYSTEM_MaxSet - hi : 0X0L);
+    return ((lo <= hi) 
+	? (~0X0L) >> lo << (lo + SYSTEM_MaxSet - hi) >> (SYSTEM_MaxSet - hi)
+	: 0X0L);
 }
 
 /*
@@ -82,15 +85,12 @@
  *	Main program
  */
 
-extern void BEGIN_MODULE();
 
 int    SYSTEM_argc;
 char **SYSTEM_argv;
 char **SYSTEM_envp;
 
-main(argc, argv, envp)
-int argc;
-char *argv[], *envp[];
+int main( int argc, char *argv[], char *envp[])
 {
   SYSTEM_argc = argc;
   SYSTEM_argv = argv;
