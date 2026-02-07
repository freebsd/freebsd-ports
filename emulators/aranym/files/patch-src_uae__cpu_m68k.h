--- src/uae_cpu/m68k.h.orig	2022-10-04 08:41:56 UTC
+++ src/uae_cpu/m68k.h
@@ -561,7 +561,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "bic %[nzcv],#0x30000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv) \
-                        : [rv] "0" (v) \
+                        : [rv] "0" ((uint32)v) \
                         : "cc"); \
         }while(0)
 
@@ -571,7 +571,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "bic %[nzcv],#0x30000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv) \
-                        : [rv] "0" (v) \
+                        : [rv] "0" ((uint32)v) \
                         : "cc"); \
         }while(0)
 
@@ -581,7 +581,7 @@ static inline int cctrue(int cc)
                         "adds %[rd],%[rd],%[rs]\n\t" \
                         "mrs %[nzcv],cpsr\n\t" \
                         : [nzcv] "=r" (regflags.nzcv), [rv] "=r" (v) \
-                        : [rs] "ri" (s), [rd] "1" (d) \
+                        : [rs] "ri" (s), [rd] "1" ((uint32)d) \
                         : "cc"); \
     COPY_CARRY(); \
     } while(0)
@@ -592,7 +592,7 @@ static inline int cctrue(int cc)
                         "adds %[rd],%[rd],%[rs]\n\t" \
                         "mrs %[nzcv],cpsr\n\t" \
                         : [nzcv] "=r" (regflags.nzcv), [rv] "=r" (v) \
-                        : [rs] "ri" (s), [rd] "1" (d) \
+                        : [rs] "ri" (s), [rd] "1" ((uint32)d) \
                         : "cc"); \
     COPY_CARRY(); \
     } while(0)
@@ -604,7 +604,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "eor %[nzcv],#0x20000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv), [rv] "=r" (v) \
-                        : [rs] "ri" (s), [rd] "1" (d) \
+                        : [rs] "ri" (s), [rd] "1" ((uint32)d) \
                         : "cc"); \
     COPY_CARRY(); \
     } while(0)
@@ -616,7 +616,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "eor %[nzcv],#0x20000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv), [rv] "=r" (v) \
-                        : [rs] "ri" (s), [rd] "1" (d) \
+                        : [rs] "ri" (s), [rd] "1" ((uint32)d) \
                         : "cc"); \
     COPY_CARRY(); \
     } while(0)
@@ -628,7 +628,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "eor %[nzcv],#0x20000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv) \
-                        : [rs] "ri" (s), [rd] "0" (d) \
+                        : [rs] "ri" (s), [rd] "0" ((uint32)d) \
                         : "cc"); \
   } while(0)
 
@@ -639,7 +639,7 @@ static inline int cctrue(int cc)
                         "mrs %[nzcv],cpsr\n\t" \
                         "eor %[nzcv],#0x20000000\n\t" \
                         : [nzcv] "=r" (regflags.nzcv) \
-                        : [rs] "ri" (s), [rd] "0" (d) \
+                        : [rs] "ri" (s), [rd] "0" ((uint32)d) \
                         : "cc"); \
   } while(0)
 
