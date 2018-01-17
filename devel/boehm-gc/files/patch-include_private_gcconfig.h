--- include/private/gcconfig.h.orig	2017-12-23 08:46:29 UTC
+++ include/private/gcconfig.h
@@ -188,7 +188,7 @@
 #      define EWS4800
 #    endif
 #    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) \
-        && !defined(OPENBSD)
+        && !defined(OPENBSD) && !defined(FREEBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #        define ULTRIX
 #      else
