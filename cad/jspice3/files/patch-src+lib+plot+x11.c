--- src/lib/plot/x11.c.orig	Thu Sep  2 21:43:35 2004
+++ src/lib/plot/x11.c	Fri Jul 21 06:06:00 2006
@@ -2205,7 +2205,7 @@
 void
 com_setrdb(wl)
 
-wordlist *wl;
+void *wl;
 {
 /* be silent */
 }
@@ -2213,7 +2213,7 @@
 int
 PopUpErrMessage(fp)
 
-File *fp;
+void *fp;
 {
     return (0);
 }
