--- rp2gen/symtab.c.orig	Fri Oct 20 09:04:36 2006
+++ rp2gen/symtab.c	Fri Oct 20 09:19:18 2006
@@ -53,6 +53,12 @@
 extern VAR *make_var();
 ENTRY *find();
 
+/*
+ * If this is not prototyped its return value defaults to int which results
+ * in bogus results on systems where sizeof(void*) > sizeof(int).
+ */
+extern RPC2_TYPE *rpc2_struct_type(VAR **);
+
 /* This module uses external chaining */
 
 #define SYMTAB_SIZE	50
