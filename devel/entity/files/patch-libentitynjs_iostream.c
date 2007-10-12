--- libentitynjs/iostream.c.orig	2007-10-12 10:20:45.000000000 +0200
+++ libentitynjs/iostream.c	2007-10-12 10:17:41.000000000 +0200
@@ -205,8 +205,9 @@ js_iostream_pipe (FILE *fp, int readp)
 
 
 size_t
-js_iostream_read (JSIOStream *stream, void *ptr, size_t size)
+js_iostream_read (JSIOStream *stream, void *vptr, size_t size)
 {
+  unsigned char	*ptr = (unsigned char *)vptr;
   size_t total = 0;
   int got;
 
@@ -233,7 +234,7 @@ js_iostream_read (JSIOStream *stream, vo
 
 	  stream->bufpos += got;
 	  size -= got;
-	  (unsigned char *) ptr += got;
+	  ptr += got;
 	  total += got;
 	}
       else
@@ -251,8 +252,9 @@ js_iostream_read (JSIOStream *stream, vo
 
 
 size_t
-js_iostream_write (JSIOStream *stream, void *ptr, size_t size)
+js_iostream_write (JSIOStream *stream, void *vptr, size_t size)
 {
+  unsigned char	*ptr = (unsigned char *)vptr;
   int space;
   size_t total = 0;
 
@@ -290,7 +292,7 @@ js_iostream_write (JSIOStream *stream, v
       stream->data_in_buf += space;
       total += space;
       size -= space;
-      (unsigned char *) ptr += space;
+      ptr += space;
 
       /* Now the buffer contains buffered write data. */
       stream->writep = 1;
