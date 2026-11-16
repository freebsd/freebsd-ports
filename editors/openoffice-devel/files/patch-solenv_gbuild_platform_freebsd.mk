--- solenv/gbuild/platform/freebsd.mk.orig	2026-11-08 23:41:08 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -299,7 +299,8 @@ gb_CXXFLAGS += -fsanitize=address
 ifeq ($(ENABLE_SANITIZER),TRUE)
 gb_CFLAGS += -fsanitize=address
 gb_CXXFLAGS += -fsanitize=address
-gb_LinkTarget_LDFLAGS += -fsanitize=address
+#gb_LinkTarget_LDFLAGS += -fsanitize=address -shared-libasan -frtlib-add-rpath
+gb_LinkTarget_LDFLAGS += -fsanitize=address -shared-libasan
 endif
 
 gb_LinkTarget_INCLUDE := $(filter-out %/stl, $(subst -I. , ,$(SOLARINC)))
