--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkFontPeer.c.orig	2013-12-16 09:40:51.000000000 +0100
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_GdkFontPeer.c	2013-12-16 09:44:06.000000000 +0100
@@ -39,10 +39,11 @@
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
 #include <pango/pangofc-font.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttypes.h>
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TYPES_H
+#include FT_TRUETYPE_TABLES_H
 #include "gdkfont.h"
 #include "gtkpeer.h"
 #include "gnu_java_awt_peer_gtk_GdkFontPeer.h"
