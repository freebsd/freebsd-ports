--- jdk/src/solaris/bin/java_md_solinux.h
+++ jdk/src/solaris/bin/java_md_solinux.h
@@ -48,6 +48,9 @@
 #ifdef __linux__
 static const char *system_dir   = "/usr/java";
 static const char *user_dir     = "/java";
+#elif defined(_ALLBSD_SOURCE)
+static const char *system_dir  = "%%LOCALBASE%%/openjdk8";
+static const char *user_dir    = "/java";
 #else /* Solaris */
 static const char *system_dir   = "/usr/jdk";
 static const char *user_dir     = "/jdk";
