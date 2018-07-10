--- gcc/cppbuiltin.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/cppbuiltin.c
@@ -127,7 +127,7 @@ static void
 define_builtin_macros_for_type_sizes (cpp_reader *pfile)
 {
 #define define_type_sizeof(NAME, TYPE)                             \
-    cpp_define_formatted (pfile, NAME"="HOST_WIDE_INT_PRINT_DEC,   \
+    cpp_define_formatted (pfile, NAME"=" HOST_WIDE_INT_PRINT_DEC,   \
                           tree_low_cst (TYPE_SIZE_UNIT (TYPE), 1))
 
   define_type_sizeof ("__SIZEOF_INT__", integer_type_node);
