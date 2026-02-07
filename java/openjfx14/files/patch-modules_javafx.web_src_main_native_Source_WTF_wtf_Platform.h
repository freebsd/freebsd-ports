--- modules/javafx.web/src/main/native/Source/WTF/wtf/Platform.h.orig	2020-07-17 12:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/Platform.h
@@ -352,6 +352,12 @@
 #endif
 #endif
 
+#if !CPU(ARM_THUMB2) && !CPU(ARM_TRADITIONAL) && !CPU(X86) && !CPU(X86_64) && !CPU(SH4) && !CPU(ARM64)
+#define ENABLE_ASSEMBLER 0
+#define ENABLE_JIT 0
+#define ENABLE_YARR_JIT 0
+#endif
+
 /* ==== OS() - underlying operating system; only to be used for mandated low-level services like
    virtual memory, not to choose a GUI toolkit ==== */
 
