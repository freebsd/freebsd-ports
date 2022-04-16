--- DevIL/src-IL/src/il_jp2.cpp.orig	2017-01-01 23:37:37 UTC
+++ DevIL/src-IL/src/il_jp2.cpp
@@ -313,14 +313,21 @@ ILboolean iLoadJp2Internal(jas_stream_t	*Stream, ILima
 }
 
 
-
-static int iJp2_file_read(jas_stream_obj_t *obj, char *buf, int cnt)
+#if JAS_VERSION_MAJOR >= 3
+static ssize_t iJp2_file_read(jas_stream_obj_t *obj, char *buf, size_t cnt)
+#else
+static int iJp2_file_read(jas_stream_obj_t *obj, char *buf, unsigned long cnt)
+#endif
 {
 	obj;
 	return iread(buf, 1, cnt);
 }
 
-static int iJp2_file_write(jas_stream_obj_t *obj, char *buf, int cnt)
+#if JAS_VERSION_MAJOR >= 3
+static ssize_t iJp2_file_write(jas_stream_obj_t *obj, const char *buf, size_t cnt)
+#else
+static int iJp2_file_write(jas_stream_obj_t *obj, const char *buf, unsigned long cnt)
+#endif
 {
 	obj;
 	return iwrite(buf, 1, cnt);
