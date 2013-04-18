--- src/libjasper/base/jas_stream.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_stream.c	2013-04-17 21:57:41.000000000 +0200
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
