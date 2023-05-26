--- src/main/cpp/blaze_util_bsd.cc.orig       1979-12-31 23:00:00 UTC
+++ src/main/cpp/blaze_util_bsd.cc
@@ -14,7 +14,7 @@
 
 #if defined(__FreeBSD__)
 # define HAVE_PROCSTAT
-# define STANDARD_JAVABASE "/usr/local/openjdk8"
+# define STANDARD_JAVABASE "%%JAVA_HOME%%"
 #elif defined(__OpenBSD__)
 # define STANDARD_JAVABASE "/usr/local/jdk-1.8.0"
 #else
