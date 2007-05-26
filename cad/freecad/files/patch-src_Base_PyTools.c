--- ./src/Base/PyTools.c.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/PyTools.c	Sun Apr 22 00:12:29 2007
@@ -447,7 +447,7 @@
     int res;               /* interact with python, in "__main__" */
     Py_Initialize();       /* in the program's "stdio" window     */
     if (prompt != NULL)
-#if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
         printf("[%s <Use Ctrl-D (i.e. EOF) to exit.>]\n", prompt);
 #else
         printf("[%s <Use Ctrl-Z plus Return to exit.>]\n", prompt);
