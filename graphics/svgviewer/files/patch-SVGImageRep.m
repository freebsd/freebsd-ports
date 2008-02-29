--- SVGImageRep.m.orig	2005-05-23 21:30:29.000000000 +0200
+++ SVGImageRep.m	2008-01-19 07:08:16.000000000 +0100
@@ -1382,8 +1382,12 @@
 
 	svg_render_context=[[SVGRenderContext alloc] init];
 
+#if 0
 	[svg_render_context prepareRender:
 		sqrt(ctm->matrix.m11*ctm->matrix.m22+ctm->matrix.m12*ctm->matrix.m21)];
+#else
+	[svg_render_context prepareRender: 1.0];
+#endif
 	svg_render(svg,&engine,svg_render_context);
 	[svg_render_context finishRender];
 
