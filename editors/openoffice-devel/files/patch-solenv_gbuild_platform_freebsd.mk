--- solenv/gbuild/platform/freebsd.mk.orig	2019-09-17 22:55:21 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -125,6 +125,7 @@ gb_LinkTarget_LDFLAGS += \
 	-Wl,-rpath-link,$(SYSBASE)/lib:$(SYSBASE)/usr/lib \
 	-Wl,-z,combreloc \
 	-Wl,-z,defs \
+	-Wl,--undefined-version \
 	$(subst -L../lib , ,$(SOLARLIB)) \
 	${FBSD_GCC_RPATH} \
 	 \
