Index: h/mh.h
diff -u h/mh.h.orig h/mh.h
--- h/mh.h.orig	Wed Dec  2 02:05:00 1998
+++ h/mh.h	Fri Jul 18 16:47:28 2003
@@ -253,7 +253,7 @@
 int     atooi ();
 char  **brkstring ();
 void	closefds ();
-char   *concat ();
+char   *concat (char *, ...);
 char   *copy ();
 char  **copyip ();
 void	cpydata ();
