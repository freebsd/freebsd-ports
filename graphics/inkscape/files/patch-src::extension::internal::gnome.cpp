--- src/extension/internal/gnome.cpp.orig	Fri Feb 18 02:44:53 2005
+++ src/extension/internal/gnome.cpp	Fri Feb 18 02:45:56 2005
@@ -183,6 +183,13 @@
     return 0;
 }
 
+unsigned int PrintGNOME::comment (Inkscape::Extension::Print * module,
+					const char * comment)
+{
+    // ignore comment
+    return 0;
+}
+
 unsigned int
 PrintGNOME::fill(Inkscape::Extension::Print *mod,
 		 NRBPath const *bpath, NRMatrix const *ctm, SPStyle const *style,
