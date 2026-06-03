Use dlsym to access environ. This avoids undefined references during linking
with -Wl,-no-undefined.

See https://reviews.freebsd.org/D30842

--- src/corelib/io/qprocess_unix.cpp.orig	2025-08-11 04:54:51 UTC
+++ src/corelib/io/qprocess_unix.cpp
@@ -59,10 +59,9 @@
 #  define _PATH_TTY     _PATH_DEV "tty"
 #endif
 
-#ifdef Q_OS_FREEBSD
-__attribute__((weak))
-#endif
+#ifndef Q_OS_FREEBSD
 extern char **environ;
+#endif
 
 QT_BEGIN_NAMESPACE
 
@@ -74,6 +73,11 @@ QProcessEnvironment QProcessEnvironment::systemEnviron
 {
     QProcessEnvironment env;
     const char *entry;
+#ifdef Q_OS_FREEBSD
+    static char* nullenv = nullptr;
+    char ***environ_p = reinterpret_cast<char***>(dlsym(RTLD_DEFAULT, "environ"));
+    char **environ = environ_p ? *environ_p : &nullenv;
+#endif
     for (int count = 0; (entry = environ[count]); ++count) {
         const char *equal = strchr(entry, '=');
         if (!equal)
