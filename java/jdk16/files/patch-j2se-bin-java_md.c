$FreeBSD$

--- ../../j2se/src/solaris/bin/java_md.c.orig	Sun Jul 29 23:03:30 2007
+++ ../../j2se/src/solaris/bin/java_md.c	Sun Jul 29 23:03:30 2007
@@ -70,10 +70,10 @@
  *      entries, but actual strings can be more efficient (with many compilers).
  */
 #if defined(__FreeBSD__)
-static const char *system_dir	= "/usr/local/jdk1.6.0";
+static const char *system_dir	= "%%LOCALBASE%%/jdk1.6.0";
 static const char *user_dir	= "/java";
 #elif defined(__OpenBSD__)
-static const char *system_dir	= "/usr/local/jdk-1.6.0";
+static const char *system_dir	= "%%LOCALBASE%%/jdk-1.6.0";
 static const char *user_dir	= "/java";
 #elif defined(__linux__)
 static const char *system_dir	= "/usr/java";
