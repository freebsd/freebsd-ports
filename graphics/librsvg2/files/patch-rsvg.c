--- rsvg.c.orig	Thu Jul 31 02:03:34 2003
+++ rsvg.c	Thu Jul 31 02:26:35 2003
@@ -332,13 +332,14 @@
 {
 	RsvgSaxHandlerGstops *z = (RsvgSaxHandlerGstops *)self;
 	RsvgHandle *ctx = z->ctx;
+	RsvgSaxHandler *prev = &z->parent->super;
 	
 	if (!strcmp((char *)name, z->parent_tag))
 		{
 			if (ctx->handler != NULL)
 				{
 					ctx->handler->free (ctx->handler);
-					ctx->handler = &z->parent->super;
+					ctx->handler = prev;
 				}
 		}
 }
@@ -679,13 +680,14 @@
 {
 	RsvgSaxHandlerStyle *z = (RsvgSaxHandlerStyle *)self;
 	RsvgHandle *ctx = z->ctx;
+	RsvgSaxHandler *prev = &z->parent->super;
 	
 	if (!strcmp ((char *)name, "style"))
 		{
 			if (ctx->handler != NULL)
 				{
 					ctx->handler->free (ctx->handler);
-					ctx->handler = &z->parent->super;
+					ctx->handler = prev;
 				}
 		}
 }
