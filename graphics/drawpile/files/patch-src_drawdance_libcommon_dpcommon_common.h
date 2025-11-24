--- src/drawdance/libcommon/dpcommon/common.h.orig	2025-11-18 11:26:42 UTC
+++ src/drawdance/libcommon/dpcommon/common.h
@@ -44,6 +44,8 @@
 #        define DP_PLATFORM "darwin"
 #    elif defined(__linux__)
 #        define DP_PLATFORM "linux"
+#    elif defined(__FreeBSD__)
+#        define DP_PLATFORM "freebsd"
 #    elif defined(__HAIKU__)
 #        define DP_PLATFORM "haiku"
 #    else
