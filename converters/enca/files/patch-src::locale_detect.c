--- src/locale_detect.c.orig	Tue Oct  8 20:11:40 2002
+++ src/locale_detect.c	Tue Oct  8 20:12:12 2002
@@ -33,9 +33,9 @@
 #  else /* HAVE_LANGINFO_H */
 char *nl_langinfo(nl_item *item);
 #  endif /* HAVE_LANGINFO_H */
+#endif /* HAVE_NL_LANGINFO */
 
 static char *codeset = NULL;
-#endif /* HAVE_NL_LANGINFO */
 
 /* Local prototypes. */
 static char* locale_alias_convert(char *locname);
