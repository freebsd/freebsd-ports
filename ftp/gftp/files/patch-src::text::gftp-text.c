--- src/text/gftp-text.c.orig	Sat Feb  5 16:38:03 2005
+++ src/text/gftp-text.c	Sat Feb  5 16:39:26 2005
@@ -185,6 +185,7 @@
   else
     infd = stdin;
 
+#if GLIB_MAJOR_VERSION > 1
   locale_question = g_locale_from_utf8 (question, -1, NULL, NULL, NULL);
   if (locale_question != NULL)
     {
@@ -193,6 +194,7 @@
       g_free (locale_question);
     }
   else
+#endif
     printf ("%s%s%s ", GFTPUI_COMMON_COLOR_BLUE, question,
             GFTPUI_COMMON_COLOR_DEFAULT);
 
