--- src/drawdance/libcommon/dpcommon/common.h.orig	2025-03-26 05:46:04 UTC
+++ src/drawdance/libcommon/dpcommon/common.h
@@ -41,6 +41,8 @@
 #        define DP_PLATFORM "darwin"
 #    elif defined(__linux__)
 #        define DP_PLATFORM "linux"
+#    elif defined(__FreeBSD__)
+#        define DP_PLATFORM "freebsd"
 #    else
 #        error "unknown platform"
 #    endif
