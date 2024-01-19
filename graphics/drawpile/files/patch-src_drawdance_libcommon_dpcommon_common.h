--- src/drawdance/libcommon/dpcommon/common.h.orig	2024-01-14 11:11:04 UTC
+++ src/drawdance/libcommon/dpcommon/common.h
@@ -40,6 +40,8 @@
 #        define DP_PLATFORM "darwin"
 #    elif defined(__linux__)
 #        define DP_PLATFORM "linux"
+#    elif defined(__FreeBSD__)
+#        define DP_PLATFORM "freebsd"
 #    else
 #        error "unknown platform"
 #    endif
