--- tests/wenju.c.orig	Sat Oct 18 05:17:33 2003
+++ tests/wenju.c	Sat Oct 18 05:17:44 2003
@@ -23,8 +23,8 @@
 
 int main(int argc, char *argv[])
 {
-    setlocale(LC_ALL, "");
 #ifdef ENABLE_NLS
+    setlocale(LC_ALL, "");
     bindtextdomain(PACKAGE, LOCALEDIR);
 #ifdef HAVE_BIND_TEXTDOMAIN_CODESET
     bind_textdomain_codeset(PACKAGE, "UTF-8");
