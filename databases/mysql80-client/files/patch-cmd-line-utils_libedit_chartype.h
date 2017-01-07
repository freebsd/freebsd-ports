--- cmd-line-utils/libedit/chartype.h.orig	2016-03-28 18:06:12 UTC
+++ cmd-line-utils/libedit/chartype.h
@@ -49,7 +49,7 @@
   TODO : Verify if FreeBSD & AIX stores ISO 10646 in wchar_t. */
 #if !defined(__NetBSD__) && !defined(__sun) \
   && !(defined(__APPLE__) && defined(__MACH__)) \
-  && !defined(__FreeBSD__) && !defined(_AIX)
+  && !defined(__FreeBSD__) && !defined(_AIX) && !defined(__DragonFly__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
