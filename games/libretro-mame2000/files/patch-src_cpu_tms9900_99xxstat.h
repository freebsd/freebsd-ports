--- src/cpu/tms9900/99xxstat.h.orig	2021-04-07 16:22:44 UTC
+++ src/cpu/tms9900/99xxstat.h
@@ -192,7 +192,7 @@ static INLINE void setst_c_lae(UINT16 to, UINT16 val)
 #define wadd(addr,expr) { int lval = setst_add_laeco(readword(addr), (expr)); writeword((addr),lval); }
 #define wsub(addr,expr) { int lval = setst_sub_laeco(readword(addr), (expr)); writeword((addr),lval); }
 
-#ifdef __POWERPC__
+#if defined(__POWERPC__) && !defined(__powerpc64__)
 
 // setst_add_32_laeco :
 // - computes a+b
