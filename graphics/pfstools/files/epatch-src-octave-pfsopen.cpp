--- src/octave/pfsopen.cpp.orig	2006-04-06 12:33:02.000000000 +0000
+++ src/octave/pfsopen.cpp	2008-02-12 10:59:44.000000000 +0000
@@ -54,8 +54,9 @@
     return retval;
   }
 
-  if( !args(0).is_string() && !args(0).is_stream() ) {
+  if( !args(0).is_string() && !args(0).is_real_scalar() ) {
     error( SCRIPT_NAME ": expected file name or file descriptor as the first argument!");
+    // file descriptors are represented as integers (stored as doubles) in Octave 3.0
     return retval;
   }
 
@@ -120,8 +121,7 @@
     }
   } else {
     // File descriptor given
-    octave_stream fid = args(0).stream_value();
-    int fd = dup( fid.file_number() );
+    int fd = dup( (int) args(0).scalar_value() );
     if( writeMode ) {
       fh = fdopen( fd, "wb" );
       if( fh == NULL ) {
