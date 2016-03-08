--- src/lib/plot/x11.c.orig	2004-09-02 21:43:35 UTC
+++ src/lib/plot/x11.c
@@ -2205,7 +2205,7 @@ ScedESC()
 void
 com_setrdb(wl)
 
-wordlist *wl;
+void *wl;
 {
 /* be silent */
 }
@@ -2213,7 +2213,7 @@ wordlist *wl;
 int
 PopUpErrMessage(fp)
 
-File *fp;
+void *fp;
 {
     return (0);
 }
