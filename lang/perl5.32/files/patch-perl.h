--- perl.h.orig	2020-12-26 15:20:27 UTC
+++ perl.h
@@ -1037,6 +1037,21 @@ EXTERN_C int usleep(unsigned int);
 #ifdef I_STDINT
     typedef intmax_t  PERL_INTMAX_T;
     typedef uintmax_t PERL_UINTMAX_T;
+    typedef intptr_t  PERL_INTPTR_T;
+    typedef uintptr_t PERL_UINTPTR_T;
+#elif PTRSIZE == PTRADDRSIZE
+    /* PERL_INTMAX_T / PERL_UINTMAX_T defined later */
+#   if PTRSIZE == 4
+       typedef I32 PERL_INTPTR_T;
+       typedef U32 PERL_UNTPTR_T;
+#   elif PTRSIZE == 8
+       typedef I64 PERL_INTPTR_T;
+       typedef U64 PERL_UNTPTR_T;
+#   else
+#      error unknown pointer size
+#   endif
+#else
+#   error stdint.h required when PTRSIZE and PTRADDRSIZE differ
 #endif
 
 /* N.B.  We use QUADKIND here instead of HAS_QUAD here, because that doesn't
@@ -1902,6 +1917,8 @@ typedef UVTYPE UV;
 
 typedef IVTYPE IV;
 typedef UVTYPE UV;
+typedef IVINTTYPE IVINT;
+typedef UVINTTYPE UVINT;
 
 #if defined(USE_64_BIT_INT) && defined(HAS_QUAD)
 #  if QUADKIND == QUAD_IS_INT64_T && defined(INT64_MAX)
@@ -1998,6 +2015,7 @@ typedef UVTYPE UV;
 #define NUM2PTR(any,d)	(any)(PTRV)(d)
 #define PTR2IV(p)	INT2PTR(IV,p)
 #define PTR2UV(p)	INT2PTR(UV,p)
+#define PTR2UVINT(p)	INT2PTR(UVINT,p)
 #define PTR2NV(p)	NUM2PTR(NV,p)
 #define PTR2nat(p)	(PTRV)(p)	/* pointer to integer of PTRSIZE */
 
