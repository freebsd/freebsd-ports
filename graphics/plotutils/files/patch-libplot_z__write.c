
$FreeBSD$

--- libplot/z_write.c.orig	Thu Aug  7 12:40:31 2003
+++ libplot/z_write.c	Thu Aug  7 12:49:08 2003
@@ -83,12 +83,12 @@
   void *error_ptr;
   png_error_ptr error_fn_ptr, warn_fn_ptr;
 #ifdef LIBPLOTTER
-  ostream *stream = _plotter->data->outstream;
-  ostream *errorstream = _plotter->data->errstream;
+  std::ostream *outstream = _plotter->data->outstream;
+  std::ostream *errstream = _plotter->data->errstream;
 #endif
 
 #ifdef LIBPLOTTER
-  if (fp == (FILE *)NULL && stream == (ostream *)NULL)
+  if (fp == (FILE *)NULL && outstream == (std::ostream *)NULL)
     return 0;
 #else
   if (fp == (FILE *)NULL)
@@ -102,11 +102,11 @@
 
   /* work out libpng error handling (i.e. callback functions and data) */
 #ifdef LIBPLOTTER
-  if (errorstream)
+  if (errstream)
     {
       error_fn_ptr = _our_error_fn_stream;
       warn_fn_ptr = _our_warn_fn_stream;
-      error_ptr = (void *)errorstream;
+      error_ptr = (void *)errstream;
     }
   else if (errorfp)
     {
@@ -158,11 +158,11 @@
     }
   
 #ifdef LIBPLOTTER
-  if (stream)
+  if (outstream)
     {
       /* use custom write and flush functions, defined below */
       png_set_write_fn (png_ptr, 
-			(void *)stream,
+			(void *)outstream,
 			(png_rw_ptr)_our_write_fn, 
 			(png_flush_ptr)_our_IO_flush_fn);
     }
@@ -481,28 +481,28 @@
 static void 
 _our_write_fn (png_struct *png_ptr, png_byte *data, png_size_t length)
 {
-  ostream *stream;
+    std::ostream *outstream;
 
-  stream = (ostream *)png_get_io_ptr (png_ptr);
-  stream->write (data, length);
+  outstream = (std::ostream *)png_get_io_ptr (png_ptr);
+  outstream->write ((const char*)data, length);
 }
 
 static void 
 _our_IO_flush_fn (png_struct *png_ptr)
 {
-  ostream *stream;
+    std::ostream *outstream;
 
-  stream = (ostream *)png_get_io_ptr (png_ptr);
-  stream->flush ();
+  outstream = (std::ostream *)png_get_io_ptr (png_ptr);
+  outstream->flush ();
 }
 
 /* custom error and warning handlers (for streams) */
 static void 
 _our_error_fn_stream (png_struct *png_ptr, const char *data)
 {
-  ostream *errstream;
+    std::ostream *errstream;
 
-  errstream = (ostream *)png_get_error_ptr (png_ptr);
+  errstream = (std::ostream *)png_get_error_ptr (png_ptr);
   if (errstream)
     {
 #ifdef PTHREAD_SUPPORT
@@ -526,9 +526,9 @@
 static void 
 _our_warn_fn_stream (png_struct *png_ptr, const char *data)
 {
-  ostream *errstream;
+    std::ostream *errstream;
 
-  errstream = (ostream *)png_get_error_ptr (png_ptr);
+  errstream = (std::ostream *)png_get_error_ptr (png_ptr);
   if (errstream)
     {
 #ifdef PTHREAD_SUPPORT
