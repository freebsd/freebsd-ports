diff -urN ../SWIG1.3a5/Lib/guile/guile.swg ./Lib/guile/guile.swg
--- ../SWIG1.3a5/Lib/guile/guile.swg	Sat Sep  2 11:25:27 2000
+++ ./Lib/guile/guile.swg	Tue Feb 27 06:12:33 2001
@@ -7,6 +7,10 @@
 
 /* SWIG pointer structure */
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 struct SwigCast {
   unsigned short      type;		  /* Index into SwigPtrTbl          */
   void               *(*cast)(void *);    /* Pointer casting function       */
@@ -140,7 +144,7 @@
   int  start, end;
   size_t *result;
   if (!SwigPtrSort) SWIG_SortTable();
-  result = bsearch(_t, SwigPtrTbl, SwigPtrN, sizeof(size_t), swigcmp);
+  result = (size_t *) bsearch(_t, SwigPtrTbl, SwigPtrN, sizeof(size_t), swigcmp);
   if (result!=NULL) return SwigPtrList+*result;
   else return NULL;
 }
@@ -246,10 +250,11 @@
 /* Convert datatype table */
 
 SWIGSTATIC
-void SWIG_Guile_RegisterTypes(swig_type_info **table)
+void SWIG_Guile_RegisterTypes(swig_type_info **table,
+                             swig_type_info **init)
 {
-  for (; *table; table++) {
-    swig_type_info *type = *table;
+  for (; *init; table++, init++) {
+    swig_type_info *type = *table = *init;
     char *origname = type->name;
     /* Register datatype itself and store pointer back */
     type->tag = SWIG_RegisterType(origname, type->str);
