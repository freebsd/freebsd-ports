--- src/giggle-diff-view.c.orig	2012-11-01 06:29:01.000000000 +0100
+++ src/giggle-diff-view.c	2014-10-01 23:37:28.640714979 +0200
@@ -27,6 +27,7 @@
 #include <libgiggle-git/giggle-git-diff.h>
 
 #include <glib/gi18n.h>
+#include <gtksourceview/gtksourcebuffer.h>
 #include <string.h>
 
 typedef struct GiggleDiffViewPriv GiggleDiffViewPriv;
