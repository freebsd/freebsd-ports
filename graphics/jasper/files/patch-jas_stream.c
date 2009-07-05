--- src/libjasper/base/jas_stream.c	Fri Jan 19 16:43:05 2007
+++ src/libjasper/base/jas_stream.c	Tue Jun 12 10:26:02 2007
@@ -362,13 +362,12 @@
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
