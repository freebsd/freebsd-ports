--- util/localize.h.orig	2013-05-03 17:17:37 UTC
+++ util/localize.h
@@ -31,9 +31,10 @@
 #  include <config.h>
 #endif
 
+#ifdef ENABLE_NLS
+
 #include <libintl.h>
 
-#ifdef ENABLE_NLS
 /** shorthand for fetching translation of default domain */
 #  define tr(s) gettext (s)
 /** shorthand for fetching translation of specified domain */
