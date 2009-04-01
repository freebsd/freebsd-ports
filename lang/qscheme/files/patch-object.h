--- object.h.orig	2009-03-03 17:43:57.000000000 +0200
+++ object.h	2009-03-03 17:54:10.000000000 +0200
@@ -51,10 +51,13 @@
 
 #define SCM_OBJECT_VAL(x)		((SCM_ObjVal*)(SCM_CAR(x)))
 #define SCM_OBJECT_DEF(x)		SCM_CDR(x)
+#define SCM_OBJECT_VAL_SET(x,v)		(SCM_CAR(x)=(v))
+#define SCM_OBJECT_DEF_SET(x,v)		(SCM_CDR(x)=(v))
 
 /*** Accessing objdef fields */
 
 #define SCM_OBJDEF_AUX(x)		((SCM_ObjDefAux*)(SCM_AUX(x)))
+#define SCM_OBJDEF_AUX_SET		SCM_AUX_SET
 #define SCM_OBJDEF_NDEFS(x)		SCM_OBJDEF_AUX(x)->ndefs
 #define SCM_OBJDEF_DEF(x,i)		(SCM_OBJDEF_AUX(x)->def + i)
 
