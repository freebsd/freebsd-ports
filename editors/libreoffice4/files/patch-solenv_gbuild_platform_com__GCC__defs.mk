--- solenv/gbuild/platform/com_GCC_defs.mk.orig	2015-04-20 19:36:29 UTC
+++ solenv/gbuild/platform/com_GCC_defs.mk
@@ -47,6 +47,8 @@ gb_CPPU_ENV := gcc3
 gb_AFLAGS := $(AFLAGS)
 
 gb_COMPILERDEFS := \
+	-DBOOST_ERROR_CODE_HEADER_ONLY \
+	-DBOOST_SYSTEM_NO_DEPRECATED \
 	-DCPPU_ENV=$(gb_CPPU_ENV) \
 
 gb_CFLAGS_COMMON := \
