--- library/tulip-ogl/src/GlGraph.cpp.orig	Wed Nov 13 22:36:00 2002
+++ library/tulip-ogl/src/GlGraph.cpp	Sat Apr 19 23:45:11 2003
@@ -39,6 +39,7 @@
 
 
 //test 
+#include <sys/types.h>
 #include <sys/timeb.h>
 
 TemplateFactory<GlyphFactory,Glyph,GlyphContext *> GlGraph::glyphFactory;
