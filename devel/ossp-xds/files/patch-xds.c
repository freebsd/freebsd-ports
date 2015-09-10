--- xds.c.orig	2005-06-02 18:50:56 UTC
+++ xds.c
@@ -383,7 +383,7 @@ int xds_vencode(xds_t *xds, const char *
 
                 /* Execute the engine. */
                 used_buffer_size = 0;
-                args_backup = args;
+                va_copy(args_backup, args);
                 rc = (*xds->engines[pos].engine)(
                          xds, xds->engines[pos].context,
                          xds->buffer + xds->buffer_len,
