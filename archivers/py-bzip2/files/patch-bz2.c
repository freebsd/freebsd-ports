--- bz2.c.orig	Tue Mar 26 13:32:03 2002
+++ bz2.c	Tue Mar 26 13:32:12 2002
@@ -1447,7 +1447,7 @@
 	int strsize;
 	int bufsize = SMALLCHUNK;
 	long totalout;
-	PyObject *ret;
+	PyObject *ret = NULL;
 	bz_stream *bzs = &self->bzs;
 	int bzerror;
 
