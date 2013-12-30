--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c.orig	2013-12-16 10:19:17.000000000 +0100
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkTextLayout.c	2013-12-16 10:19:47.000000000 +0100
@@ -42,8 +42,9 @@
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
 #include <pango/pangofc-font.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 #include "native_state.h"
 #include "gdkfont.h"
 #include "gnu_java_awt_peer_gtk_GdkTextLayout.h"
