--- ./solenv/gbuild/platform/com_GCC_defs.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./solenv/gbuild/platform/com_GCC_defs.mk	2012-04-16 15:52:47.000000000 +0200
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
