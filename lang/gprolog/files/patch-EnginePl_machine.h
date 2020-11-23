--- EnginePl/machine.h.orig	2015-01-13 18:00:19 UTC
+++ EnginePl/machine.h
@@ -124,7 +124,7 @@ void M_Check_Magic_Words(void); /* not c
 #    define M_USED_REGS            {"$9", "$10", "$11", "$12", "$13", "$14", 0}
 
 /* on M_ix86_darwin : %ebx is used by gcc for pic base */
-#elif defined(M_ix86) && !defined(_MSC_VER) && !defined(M_ix86_darwin)
+#elif defined(M_ix86) && !defined(_MSC_VER) && !defined(M_ix86_darwin) && !defined(__clang__)
 
 #ifdef NO_USE_EBP
 #    define M_USED_REGS            {"ebx", 0}
@@ -137,7 +137,7 @@ void M_Check_Magic_Words(void); /* not c
 #    define M_USED_REGS            {"15", "20", 0}
 
 /* on M_x86_64_darwin Lion r12-r15 do not work (why ?) */
-#elif defined(M_x86_64) && !defined(_MSC_VER) && !defined(M_x86_64_darwin)
+#elif defined(M_x86_64) && !defined(_MSC_VER) && !defined(M_x86_64_darwin) && !defined(__clang__)
 
 #    define M_USED_REGS            {"r12", "r13", "r14", "r15", 0}
 
