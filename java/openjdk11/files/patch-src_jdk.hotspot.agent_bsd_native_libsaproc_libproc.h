This patch fixes the following error:

In file included from /usr/ports/java/openjdk11/work/jdk11u-jdk-11.0.24-8-1/src/jdk.hotspot.agent/bsd/native/libsaproc/ps_proc.c:40:
In file included from /usr/ports/java/openjdk11/work/jdk11u-jdk-11.0.24-8-1/src/jdk.hotspot.agent/bsd/native/libsaproc/libproc_impl.h:30:
/usr/ports/java/openjdk11/work/jdk11u-jdk-11.0.24-8-1/src/jdk.hotspot.agent/bsd/native/libsaproc/libproc.h:79:13: error: cannot combine with previous 'int' declaration specifier
   79 | typedef int bool;
      |             ^
/usr/include/stdbool.h:37:14: note: expanded from macro 'bool'
   37 | #define bool    _Bool


--- src/jdk.hotspot.agent/bsd/native/libsaproc/libproc.h.orig	2024-10-07 16:02:52.117023000 +0200
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/libproc.h	2024-10-07 16:02:15.020023000 +0200
@@ -76,9 +76,11 @@ typedef int bool;
 
 // This C bool type must be int for compatibility with BSD calls and
 // it would be a mistake to equivalence it to C++ bool on many platforms
+#if defined(__FreeBSD__) && !defined(__bool_true_false_are_defined)
 typedef int bool;
 #define true  1
 #define false 0
+#endif  // __FreeBSD__ && !__bool_true_false_are_defined
 
 #endif // __APPLE__
 
