--- kdevelop/tools/processesend.pl.orig	Fri Mar 23 13:27:51 2001
+++ kdevelop/tools/processesend.pl	Fri Mar 23 13:29:21 2001
@@ -34,7 +34,7 @@
   printflush (STDOUT,"creating configuration files...\n");
   printflush (STDOUT,">make -f Makefile.dist\n");
   chdir ($overDirectory);
-  system ("make -f Makefile.dist");
+  system ("gmake -f Makefile.dist");
   
   #start configure
   printflush (STDOUT,"make configure...\n");
@@ -109,7 +109,7 @@
     if ($processes{XGETTEXT} && $processes{XGETTEXT} eq "yes")
     {
       printflush (STDOUT,">make messages\n");
-      system ("make messages >/dev/null");
+      system ("gmake messages >/dev/null");
     }
     else
     {
@@ -125,7 +125,7 @@
     {
       chdir ($overDirectory);
       printflush (STDOUT,">make -f admin/Makefile.common package-messages\n");
-      system ("make -f admin/Makefile.common package-messages >/dev/null");
+      system ("gmake -f admin/Makefile.common package-messages >/dev/null");
     }
     else
     {
