--- solenv/inc/unxfbsd.mk.orig	2026-11-08 23:41:08 UTC
+++ solenv/inc/unxfbsd.mk
@@ -211,7 +211,8 @@ LINKFLAGSOPT=
 
 # Flag for enabling address sanitizer
 .IF "$(ENABLE_SANITIZER)"=="TRUE"
-LINKFLAGS += -fsanitize=address
+#LINKFLAGS += -fsanitize=address -shared-libasan -frtlib-add-rpath
+LINKFLAGS += -fsanitize=address -shared-libasan 
 .ENDIF
 
 # linker flags for optimization (symbol hashtable)
