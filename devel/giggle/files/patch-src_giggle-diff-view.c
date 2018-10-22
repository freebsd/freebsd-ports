--- src/giggle-diff-view.c.orig	2012-11-01 05:29:01 UTC
+++ src/giggle-diff-view.c
@@ -27,6 +27,7 @@
 #include <libgiggle-git/giggle-git-diff.h>
 
 #include <glib/gi18n.h>
+#include <gtksourceview/gtksource.h>
 #include <string.h>
 
 typedef struct GiggleDiffViewPriv GiggleDiffViewPriv;
