--- cut-n-paste/synctex/synctex_parser_utils.c.orig	2014-03-12 12:47:17.715798580 +0000
+++ cut-n-paste/synctex/synctex_parser_utils.c	2014-03-12 12:46:48.989847341 +0000
@@ -103,7 +103,10 @@
 	}
 #   else
 	result = fprintf(stderr,"SyncTeX ERROR: ");
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
 	result += vfprintf(stderr, reason, arg);
+#pragma clang diagnostic pop
 	result += fprintf(stderr,"\n");
 #   endif
 	va_end (arg);
