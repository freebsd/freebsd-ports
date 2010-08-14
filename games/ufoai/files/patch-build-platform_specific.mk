--- build/platform_specific.mk	2010-08-12 03:25:05.000000000 -0500
+++ build/platform_specific.mk	2010-08-12 03:25:19.000000000 -0500
@@ -55,6 +55,7 @@
 # FreeBSD like
 ifeq ($(TARGET_OS),freebsd)
 	CFLAGS+=-D_BSD_SOURCE -D_XOPEN_SOURCE
+	LDFLAGS+=-lexecinfo
 endif
 
 ifeq ($(TARGET_OS),netbsd)
