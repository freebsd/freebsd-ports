--- rsvg-paint-server.c.orig	Tue Jan 25 23:39:10 2005
+++ rsvg-paint-server.c	Tue Jan 25 23:39:19 2005
@@ -84,10 +84,10 @@
 								const RsvgPSCtx *ctx)
 {
 	RsvgPaintServerSolid *z = (RsvgPaintServerSolid *)self;
+	ArtPixMaxDepth color[3];
 	guint32 rgb = z->rgb;
 	if (z->currentcolour)
 		rgb = rsvg_state_current(ctx->ctx)->current_color;
-	ArtPixMaxDepth color[3];
 	
 	color[0] = ART_PIX_MAX_FROM_8 (rgb >> 16);
 	color[1] = ART_PIX_MAX_FROM_8 ((rgb >> 8) & 0xff);
