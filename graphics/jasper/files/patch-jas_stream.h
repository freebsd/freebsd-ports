--- src/libjasper/include/jasper/jas_stream.h.orig	2007-01-19 22:43:04.000000000 +0100
+++ src/libjasper/include/jasper/jas_stream.h	2015-08-29 07:54:41.000000000 +0200
@@ -215,7 +215,7 @@
 	uchar *bufstart_;
 
 	/* The buffer size. */
-	int bufsize_;
+	size_t bufsize_;
 
 	/* The current position in the buffer. */
 	uchar *ptr_;
@@ -267,7 +267,7 @@
 	uchar *buf_;
 
 	/* The allocated size of the buffer for holding file data. */
-	int bufsize_;
+	size_t bufsize_;
 
 	/* The length of the file. */
 	int_fast32_t len_;
@@ -291,7 +291,7 @@
 jas_stream_t *jas_stream_fopen(const char *filename, const char *mode);
 
 /* Open a memory buffer as a stream. */
-jas_stream_t *jas_stream_memopen(char *buf, int bufsize);
+jas_stream_t *jas_stream_memopen(char *buf, size_t bufsize);
 
 /* Open a file descriptor as a stream. */
 jas_stream_t *jas_stream_fdopen(int fd, const char *mode);
@@ -366,7 +366,7 @@
 int jas_stream_puts(jas_stream_t *stream, const char *s);
 
 /* Read a line of input from a stream. */
-char *jas_stream_gets(jas_stream_t *stream, char *buf, int bufsize);
+char *jas_stream_gets(jas_stream_t *stream, char *buf, size_t bufsize);
 
 /* Look at the next character to be read from a stream without actually
   removing it from the stream. */
