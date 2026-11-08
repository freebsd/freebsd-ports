--- src/common/RTMath.cpp.orig	2025-11-21 20:00:06 UTC
+++ src/common/RTMath.cpp
@@ -54,17 +54,7 @@ RTMathBase::time_stamp_t RTMathBase::CreateTimeStamp()
     return t;
     #elif defined(__powerpc__)
     time_stamp_t t;
-    __asm__ __volatile__ (
-        "98:	mftb %0\n"
-        "99:\n"
-        ".section __ftr_fixup,\"a\"\n"
-        "	.long %1\n"
-        "	.long 0\n"
-        "	.long 98b\n"
-        "	.long 99b\n"
-        ".previous"
-        : "=r" (t) : "i" (0x00000100)
-    );
+    __asm__ __volatile__ ("mftb %0" : "=r" (t));
     return t;
     #elif defined(__alpha__)
     time_stamp_t t;
