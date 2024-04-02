--- configs/freebsd.mk.orig	2024-02-07 07:40:03 UTC
+++ configs/freebsd.mk
@@ -5,7 +5,7 @@ ARCH = x86_64
 # variables used during build
 PLATFORM = freebsd
 ARCH = x86_64
-HARECFLAGS =
+HARECFLAGS = -a ${ARCH}
 QBEFLAGS =
 ASFLAGS =
 LDLINKFLAGS = --gc-sections -z noexecstack
