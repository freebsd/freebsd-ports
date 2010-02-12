--- src/DSC/DSC_User/Datastream/Calcium/fortoc.h.orig	2009-05-20 10:42:12.000000000 +0700
+++ src/DSC/DSC_User/Datastream/Calcium/fortoc.h	2009-05-20 10:12:48.000000000 +0700
@@ -36,5 +36,17 @@
 
 #endif
 
+#ifdef  __freebsd__
+#define F_FUNC(lname,uname) _(lname,_)        /* Fortran function name */
+#define F_CALL(lname,uname) _(lname,_)        /* Fortran function call */
+#define STR_PSTR(str)       char *str         /* fortran string arg pointer */
+#define STR_PLEN(str)       , int _(Len,str)  /* fortran string arg length */
+#define STR_PTR(str)        str               /* fortran string pointer */
+#define STR_LEN(str)        _(Len,str)        /* fortran string length */
+
+
+#endif
+
+
 #endif
 
