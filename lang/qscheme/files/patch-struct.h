--- struct.h.orig	2009-03-03 17:59:24.000000000 +0200
+++ struct.h	2009-03-03 18:02:41.000000000 +0200
@@ -10,6 +10,8 @@
 #define SCM_DBLOCKP(x)			(SCM_OBJTYPE(x) == SOBJ_T_DBLOCK)
 #define SCM_DBLOCK_ADDR(x)		((void*)SCM_CAR(x))
 #define SCM_DBLOCK_SIZE(x)		((long)(SCM_CDR(x)))
+#define SCM_DBLOCK_ADDR_SET(x,v)	(SCM_CAR(x)=(v))
+#define SCM_DBLOCK_SIZE_SET(x,v)	(SCM_CDR(x)=(v))
 
 #define SCM_DBLOCK_ALLOCATED	(1L << ((sizeof(long)*8)-1))
 #define SCM_DBLOCK_SIZE_MASK	~(SCM_DBLOCK_ALLOCATED)
@@ -34,6 +36,7 @@
 
 #define SCM_STRUCT_DEFP(x)		(SCM_OBJTYPE(x) == SOBJ_T_STRUCT_DEF)
 #define SCM_STRUCT_DEF(x)		((SCM_StructDefAux *)SCM_AUX(x))
+#define SCM_STRUCT_DEF_SET		SCM_AUX_SET
 
 /*** Instance of a struct:
  *	- car points to struct def object,
