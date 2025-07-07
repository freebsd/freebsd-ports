--- components/crashcatcher/crashcatcher.cpp.orig	2025-07-01 11:41:15 UTC
+++ components/crashcatcher/crashcatcher.cpp
@@ -95,6 +95,8 @@ namespace
         { ILL_PRVREG, "Privileged register" },
         { ILL_COPROC, "Coprocessor error" },
         { ILL_BADSTK, "Internal stack error" },
+#else
+        { 0, nullptr },
 #endif
     };
 
@@ -113,6 +115,8 @@ namespace
 #ifndef __FreeBSD__
         { SEGV_MAPERR, "Address not mapped to object" },
         { SEGV_ACCERR, "Invalid permissions for mapped object" },
+#else
+        { 0, nullptr },
 #endif
     };
 
@@ -121,6 +125,8 @@ namespace
         { BUS_ADRALN, "Invalid address alignment" },
         { BUS_ADRERR, "Non-existent physical address" },
         { BUS_OBJERR, "Object specific hardware error" },
+#else
+        { 0, nullptr },
 #endif
     };
 
