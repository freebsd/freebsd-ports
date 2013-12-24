--- native/jni/gtk-peer/gnu_java_awt_peer_gtk_FreetypeGlyphVector.c.orig	2013-12-16 09:41:00.000000000 +0100
+++ native/jni/gtk-peer/gnu_java_awt_peer_gtk_FreetypeGlyphVector.c	2013-12-16 09:42:44.000000000 +0100
@@ -42,8 +42,9 @@
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
 #include <pango/pangofc-font.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 #include "jcl.h"
 #include "gdkfont.h"
 #include "gnu_java_awt_peer_gtk_FreetypeGlyphVector.h"
