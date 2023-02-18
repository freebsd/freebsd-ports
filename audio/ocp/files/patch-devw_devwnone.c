--- devw/devwnone.c.orig	2023-02-18 17:11:26 UTC
+++ devw/devwnone.c
@@ -493,7 +493,7 @@ static const struct mcpDevAPI_t *devwNoneInit (const s
 	return &devwNone;
 }
 
-static void devwNoneClose (const struct mcpDriver_t *)
+static void devwNoneClose (const struct mcpDriver_t *driver)
 {
 }
 
