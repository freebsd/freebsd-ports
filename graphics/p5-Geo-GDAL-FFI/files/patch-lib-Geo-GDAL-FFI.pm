--- lib/Geo/GDAL/FFI.pm.orig	2021-03-16 05:39:02 UTC
+++ lib/Geo/GDAL/FFI.pm
@@ -433,7 +433,7 @@ sub new {
 
     my $ffi = FFI::Platypus->new;
     $ffi->load_custom_type('::StringPointer' => 'string_pointer');
-    $ffi->lib(Alien::gdal->dynamic_libs);
+    $ffi->lib(['%%LOCALBASE%%/lib/libgdal.so']);
 
     $ffi->type('(pointer,size_t,size_t,opaque)->size_t' => 'VSIWriteFunction');
     $ffi->type('(int,int,string)->void' => 'CPLErrorHandler');
