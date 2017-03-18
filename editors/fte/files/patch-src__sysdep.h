--- src/sysdep.h.orig	2011-06-29 22:32:34 UTC
+++ src/sysdep.h
@@ -21,6 +21,7 @@
     !defined(IRIX) && \
     !defined(SCO) && \
     !defined(SUNOS) && \
+    !defined(FREEBSD) && \
     !defined(NCR)
 #    error Target not supported.
 #endif
