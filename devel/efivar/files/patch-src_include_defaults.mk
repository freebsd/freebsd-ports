--- src/include/defaults.mk.orig	2024-01-31 20:08:46 UTC
+++ src/include/defaults.mk
@@ -43,7 +43,6 @@ override CFLAGS = $(_CFLAGS) \
 override CFLAGS = $(_CFLAGS) \
 		  -std=gnu11 \
 		  -funsigned-char \
-		  -fvisibility=hidden \
 		  $(call family,CFLAGS) \
 		  $(call pkg-config-cflags)
 LDFLAGS_CLANG ?= -rtlib=compiler-rt
@@ -53,7 +52,6 @@ override LDFLAGS = $(CFLAGS) -L. $(_LDFLAGS) $(_CCLDFL
 override _LDFLAGS := $(LDFLAGS)
 override LDFLAGS = $(CFLAGS) -L. $(_LDFLAGS) $(_CCLDFLAGS) \
 		   -Wl,--build-id \
-		   -Wl,--no-allow-shlib-undefined \
 		   -Wl,--no-undefined-version \
 		   -Wl,-z,now \
 		   -Wl,-z,muldefs \
@@ -99,7 +97,6 @@ override HOST_LDFLAGS = $(HOST_CFLAGS) -L. \
 override HOST_LDFLAGS = $(HOST_CFLAGS) -L. \
 			$(_HOST_LDFLAGS) $(_HOST_CCLDFLAGS) \
 			-Wl,--build-id \
-			-Wl,--no-allow-shlib-undefined \
 			-Wl,-z,now \
 			-Wl,-z,muldefs \
 			$(call family,HOST_LDFLAGS) \
