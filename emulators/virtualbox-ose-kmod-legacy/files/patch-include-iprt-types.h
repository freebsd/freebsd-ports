- Fix build failure on FreeBSD 10-CURRENT after r228444

include/iprt/types.h:174: error: redefinition of typedef 'bool'
@/sys/types.h:271: error: previous declaration of 'bool' was here

Submitted by:	Daichi GOTO <daichi@freebsd.org>
--- include/iprt/types.h.orig	2011-10-28 16:29:51.000000000 +0200
+++ include/iprt/types.h	2011-12-22 10:17:16.000000000 +0100
@@ -167,6 +167,10 @@
 # if defined(__GNUC__)
 #  if defined(RT_OS_LINUX) && __GNUC__ < 3
 typedef uint8_t bool;
+#  elif defined(RT_OS_FREEBSD)
+#   ifndef __bool_true_false_are_defined
+typedef _Bool bool;
+#   endif
 #  else
 #   if defined(RT_OS_DARWIN) && defined(_STDBOOL_H)
 #    undef bool
