--- source/callproc.c.orig	Mon Jun  9 13:22:12 2003
+++ source/callproc.c	Mon Jun  9 13:22:58 2003
@@ -505,6 +505,13 @@
 #undef ffi_type_slong
 #define ffi_type_slong ffi_type_sint32
 #define ffi_type_slonglong ffi_type_sint64
+#elif (SIZEOF_LONG_LONG == 8 && SIZEOF_LONG == 8)
+#undef ffi_type_ulong
+#define ffi_type_ulong ffi_type_uint64
+#define ffi_type_ulonglong ffi_type_uint64
+#undef ffi_type_slong
+#define ffi_type_slong ffi_type_sint64
+#define ffi_type_slonglong ffi_type_sint64
 #endif
 
 	atypes = (ffi_type **)alloca(argcount * sizeof(ffi_type *));
