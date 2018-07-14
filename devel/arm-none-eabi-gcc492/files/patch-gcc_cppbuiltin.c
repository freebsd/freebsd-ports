--- gcc/cppbuiltin.c.orig	2014-01-24 23:13:49 UTC
+++ gcc/cppbuiltin.c
@@ -129,7 +129,7 @@ static void
 define_builtin_macros_for_type_sizes (cpp_reader *pfile)
 {
 #define define_type_sizeof(NAME, TYPE)                             \
-    cpp_define_formatted (pfile, NAME"="HOST_WIDE_INT_PRINT_DEC,   \
+    cpp_define_formatted (pfile, NAME "=" HOST_WIDE_INT_PRINT_DEC, \
                           tree_to_uhwi (TYPE_SIZE_UNIT (TYPE)))
 
   define_type_sizeof ("__SIZEOF_INT__", integer_type_node);
