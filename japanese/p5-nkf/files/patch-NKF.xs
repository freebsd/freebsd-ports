--- NKF.xs.orig	2009-01-20 18:49:31.000000000 +0900
+++ NKF.xs	2009-04-12 22:34:31.574328548 +0900
@@ -95,7 +95,10 @@
 
 #define PERL_XS 1
 #include "../utf8tbl.c"
+#undef SP
 #include "../nkf.c"
+#undef SP
+#define SP sp /* perl's CORE/pp.h */
 
 /* package defenition  */
 
@@ -134,9 +137,6 @@
     data = SvPV(ST(argc),i_len);
     input_ctr = 0;
 
-    if(x0201_f == WISH_TRUE)
-         x0201_f = ((!iso2022jp_f)? TRUE : NO_X0201);
-
     /* allocate the result buffer */
 
     /* During conversion, stirngs length may grow. This is the unit */
@@ -178,9 +178,6 @@
     data = SvPV(ST(0),i_len);
     input_ctr = 0;
 
-    if(x0201_f == WISH_TRUE)
-         x0201_f = ((!iso2022jp_f)? TRUE : NO_X0201);
-
     /* allocate the result buffer */
 
     /* During conversion, stirngs length may grow. This is the unit */
