--- arts_helper.c.orig	Tue Apr  6 02:23:37 2004
+++ arts_helper.c	Tue Apr  6 02:22:32 2004
@@ -243,7 +243,9 @@
 {
 	going = 0;
 	arts_close_stream(handle);
+#if 0
 	arts_free();
+#endif
 }
 
 static int read_all(int fd, void *buf, size_t count)
