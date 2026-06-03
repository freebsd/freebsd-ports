--- compiler_flags.mk.orig	2026-04-29 07:48:52 UTC
+++ compiler_flags.mk
@@ -16,7 +16,9 @@ COMPILER_TYPE=	gcc
 #
 # At least `drivers/gpu/drm/drm_atomic_uapi.c` and
 # `include/drm/drm_atomic_uap.h` depends on this to compile.
+.if exists(${SYSDIR}/compat/linuxkpi/common/include/linux/compiler_types.h)
 CFLAGS+=	-include ${SYSDIR}/compat/linuxkpi/common/include/linux/compiler_types.h
+.endif
 
 CWARNFLAGS+=	-Wno-pointer-sign
 
