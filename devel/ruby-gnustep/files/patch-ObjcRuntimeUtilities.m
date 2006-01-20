RCS file: /sources/gnustep/gnustep/dev-libs/ruby/Source/ObjcRuntimeUtilities.m,v
retrieving revision 1.3
retrieving revision 1.4
diff -u -r1.3 -r1.4
--- Source/ObjcRuntimeUtilities.m	2001/09/24 11:48:14	1.3
+++ Source/ObjcRuntimeUtilities.m	2005/03/28 02:21:28	1.4
@@ -56,7 +56,7 @@
 			      const char *superclassName, 
 			      int ivarNumber, ...)
 {
-  objc_EXPORT void __objc_exec_class (Module_t module);
+  objc_EXPORT void __objc_exec_class (void *module);
   objc_EXPORT void __objc_resolve_class_links ();
   Module_t module;
   Symtab_t symtab;
