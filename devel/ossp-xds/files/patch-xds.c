--- xds.c.orig	Mon Feb 17 21:33:40 2003
+++ xds.c	Sat May 29 19:07:41 2004
@@ -383,7 +383,11 @@
 
                 /* Execute the engine. */
                 used_buffer_size = 0;
+#ifdef __amd64__
+                va_copy(args_backup, args);
+#else
                 args_backup = args;
+#endif
                 rc = (*xds->engines[pos].engine)(
                          xds, xds->engines[pos].context,
                          xds->buffer + xds->buffer_len,
