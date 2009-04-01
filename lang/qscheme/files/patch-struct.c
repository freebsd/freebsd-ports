--- struct.c.orig	2009-03-03 17:58:54.000000000 +0200
+++ struct.c	2009-03-03 18:02:57.000000000 +0200
@@ -24,8 +24,10 @@
 	ptr = scm_must_alloc(size);
 	size |= SCM_DBLOCK_ALLOCATED;
   }
-  SCM_DBLOCK_ADDR(new) = ptr;
-  SCM_DBLOCK_SIZE(new) = size;
+  /*SCM_DBLOCK_ADDR(new) = ptr;
+  SCM_DBLOCK_SIZE(new) = size;*/
+  SCM_DBLOCK_ADDR_SET(new, ptr);
+  SCM_DBLOCK_SIZE_SET(new, size);
   return(new);
 }
 
@@ -33,8 +35,10 @@
 {
   if (SCM_DBLOCK_SIZE(x) & SCM_DBLOCK_ALLOCATED) {
 	scm_free(SCM_DBLOCK_ADDR(x));
-	SCM_DBLOCK_ADDR(x) = NULL;
-	SCM_DBLOCK_SIZE(x) = 0;
+	/*SCM_DBLOCK_ADDR(x) = NULL;
+	SCM_DBLOCK_SIZE(x) = 0;*/
+	SCM_DBLOCK_ADDR_SET(x, NULL);
+	SCM_DBLOCK_SIZE_SET(x, 0);
   }
 }
 
@@ -136,7 +140,8 @@
 SOBJ scm_struct_def_new(int nfields)
 {
   SOBJ new = scm_newcell(SOBJ_T_STRUCT_DEF);
-  SCM_STRUCT_DEF(new) = scm_struct_def_alloc(nfields);
+  /*SCM_STRUCT_DEF(new) = scm_struct_def_alloc(nfields);*/
+  SCM_STRUCT_DEF_SET(new, scm_struct_def_alloc(nfields));
   return(new);
 }
 
@@ -156,7 +161,8 @@
 {
   if (SCM_STRUCT_DEF(x)) {
 	scm_free(SCM_STRUCT_DEF(x));
-	SCM_STRUCT_DEF(x) = NULL;
+	/*SCM_STRUCT_DEF(x) = NULL;*/
+	SCM_STRUCT_DEF_SET(x, NULL);
   }
 }
 
