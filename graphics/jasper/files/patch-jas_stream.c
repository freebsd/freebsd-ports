--- src/libjasper/base/jas_stream.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_stream.c	2015-08-29 08:07:01.000000000 +0200
@@ -99,7 +99,7 @@
 static void jas_stream_destroy(jas_stream_t *stream);
 static jas_stream_t *jas_stream_create(void);
 static void jas_stream_initbuf(jas_stream_t *stream, int bufmode, char *buf,
-  int bufsize);
+  size_t bufsize);
 
 static int mem_read(jas_stream_obj_t *obj, char *buf, int cnt);
 static int mem_write(jas_stream_obj_t *obj, char *buf, int cnt);
@@ -168,7 +168,7 @@
 	return stream;
 }
 
-jas_stream_t *jas_stream_memopen(char *buf, int bufsize)
+jas_stream_t *jas_stream_memopen(char *buf, size_t bufsize)
 {
 	jas_stream_t *stream;
 	jas_stream_memobj_t *obj;
@@ -361,15 +361,14 @@
 	}
 	obj->fd = -1;
 	obj->flags = 0;
-	obj->pathname[0] = '\0';
+	snprintf(obj->pathname, sizeof(obj->pathname), "/tmp/jasper.XXXXXX");
 	stream->obj_ = obj;
 
 	/* Choose a file name. */
-	tmpnam(obj->pathname);
+	obj->fd = mkstemp(obj->pathname);
 
 	/* Open the underlying file. */
-	if ((obj->fd = open(obj->pathname, O_CREAT | O_EXCL | O_RDWR | O_TRUNC | O_BINARY,
-	  JAS_STREAM_PERMS)) < 0) {
+	if (obj->fd < 0) {
 		jas_stream_destroy(stream);
 		return 0;
 	}
@@ -553,7 +552,7 @@
 	int ret;
 
 	va_start(ap, fmt);
-	ret = vsprintf(buf, fmt, ap);
+	ret = vsnprintf(buf, sizeof(buf), fmt, ap);
 	jas_stream_puts(stream, buf);
 	va_end(ap);
 	return ret;
@@ -570,7 +569,7 @@
 	return 0;
 }
 
-char *jas_stream_gets(jas_stream_t *stream, char *buf, int bufsize)
+char *jas_stream_gets(jas_stream_t *stream, char *buf, size_t bufsize)
 {
 	int c;
 	char *bufptr;
@@ -694,7 +693,7 @@
 \******************************************************************************/
 
 static void jas_stream_initbuf(jas_stream_t *stream, int bufmode, char *buf,
-  int bufsize)
+  size_t bufsize)
 {
 	/* If this function is being called, the buffer should not have been
 	  initialized yet. */
@@ -987,7 +986,7 @@
 	return cnt;
 }
 
-static int mem_resize(jas_stream_memobj_t *m, int bufsize)
+static int mem_resize(jas_stream_memobj_t *m, size_t bufsize)
 {
 	unsigned char *buf;
 
