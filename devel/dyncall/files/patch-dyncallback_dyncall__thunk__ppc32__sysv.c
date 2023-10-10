--- dyncallback/dyncall_thunk_ppc32_sysv.c.orig	2023-10-10 15:09:47 UTC
+++ dyncallback/dyncall_thunk_ppc32_sysv.c
@@ -25,8 +25,8 @@
 
 #include "dyncall_thunk.h"
 
-static unsigned short hi16(x) { return ( (unsigned short) (((unsigned int)x)>>16UL) ); }
-static unsigned short lo16(x) { return ( (unsigned short)  ((unsigned int)x)        ); }   
+static unsigned short hi16(DCThunk* x) { return ( (unsigned short) (((unsigned int)x)>>16UL) ); }
+static unsigned short lo16(DCThunk* x) { return ( (unsigned short)  ((unsigned int)x)        ); }   
 
 void dcbInitThunk(DCThunk* p, void (*entry)())
 {
