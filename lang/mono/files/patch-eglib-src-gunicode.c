--- eglib/src/gunicode.c.orig
+++ eglib/src/gunicode.c
@@ -219,10 +219,10 @@
 		is_utf8 = FALSE;
 #else
 		/* These shouldn't be heap allocated */
-#if HAVE_LOCALCHARSET_H
-		my_charset = locale_charset ();
-#elif defined(HAVE_LANGINFO_H)
+#if defined(HAVE_LANGINFO_H)
 		my_charset = nl_langinfo (CODESET);
+#elif defined(HAVE_LOCALCHARSET_H)
+		my_charset = locale_charset ();
 #else
 		my_charset = "UTF-8";
 #endif
