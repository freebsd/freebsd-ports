--- solenv/gbuild/platform/freebsd.mk.orig	2014-02-25 08:33:29 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -96,6 +96,7 @@ gb_CXXFLAGS := \
 	-fvisibility-inlines-hidden \
 	-fvisibility=hidden \
 	-pipe \
+	-DHAVE_STL_INCLUDE_PATH \
 
 ifneq ($(EXTERNAL_WARNINGS_NOT_ERRORS),TRUE)
 gb_CFLAGS_WERROR := -Werror
@@ -110,7 +111,6 @@ endif
 gb_LinkTarget_EXCEPTIONFLAGS := \
 	-DEXCEPTIONS_ON \
 	-fexceptions \
-	-fno-enforce-eh-specs \
 
 gb_LinkTarget_NOEXCEPTIONFLAGS := \
 	-DEXCEPTIONS_OFF \
@@ -121,6 +121,7 @@ gb_LinkTarget_LDFLAGS += \
 	-Wl,-z,combreloc \
 	-Wl,-z,defs \
 	$(subst -L../lib , ,$(SOLARLIB)) \
+	${FBSD_LDFLAGS} \
 	 \
 
 ifeq ($(HAVE_LD_HASH_STYLE),TRUE)
