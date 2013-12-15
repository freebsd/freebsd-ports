--- src/globalstrings.h.orig	2013-12-16 00:04:58.000000000 +0100
+++ src/globalstrings.h	2013-12-16 00:05:20.000000000 +0100
@@ -21,7 +21,7 @@
 #ifndef REGEXXER_GLOBALSTRINGS_H_INCLUDED
 #define REGEXXER_GLOBALSTRINGS_H_INCLUDED
 
-#include <glib/gutils.h>  /* for G_DIR_SEPARATOR_S */
+#include <glib.h>  /* for G_DIR_SEPARATOR_S */
 
 namespace Regexxer
 {
