--- plug-ins/print/print.c.orig	Tue Dec 26 07:43:54 2000
+++ plug-ins/print/print.c	Tue Dec 26 07:44:07 2000
@@ -1417,7 +1417,7 @@
 
     if (i < (sizeof(lpcs) / sizeof(lpcs[0])))
     {
-      strcat(command, " status < /dev/null");
+      strcat(command, " status all < /dev/null");
       type = PRINTERS_LPC;
     }
     else
