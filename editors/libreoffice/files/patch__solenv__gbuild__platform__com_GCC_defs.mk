--- solenv/gbuild/platform/com_GCC_defs.mk.orig	2012-02-01 13:56:49.000000000 +0100
+++ solenv/gbuild/platform/com_GCC_defs.mk	2012-03-01 08:38:34.634457577 +0100
@@ -113,8 +113,13 @@
 
 gb_LinkTarget_EXCEPTIONFLAGS := \
 	-DEXCEPTIONS_ON \
-	-fexceptions \
-	-fno-enforce-eh-specs \
+	-fexceptions
+
+# Clang doesn't have this option
+ifeq (,$(findstring /clang,$(CXX)))
+gb_LinkTarget_EXCEPTIONFLAGS += \
+	-fno-enforce-eh-specs
+endif
 
 gb_LinkTarget_NOEXCEPTIONFLAGS := \
 	-DEXCEPTIONS_OFF \
