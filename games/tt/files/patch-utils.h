--- utils.h.orig	Fri Sep 12 22:12:44 2003
+++ utils.h	Fri Sep 12 22:13:00 2003
@@ -12,7 +12,7 @@
 \***************************************************************************/
 
 extern char *basename ();
-extern char *form ();
+extern char *form (const char *fmt_string, ...);
 extern void die ();
 extern void get_termcap ();
 extern void flush_keyboard ();
