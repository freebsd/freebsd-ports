Index: h/mh.h
--- h/mh.h.orig	1998-12-01 17:05:00 UTC
+++ h/mh.h
@@ -253,7 +253,7 @@ void	ambigsw ();
 int     atooi ();
 char  **brkstring ();
 void	closefds ();
-char   *concat ();
+char   *concat (char *, ...);
 char   *copy ();
 char  **copyip ();
 void	cpydata ();
