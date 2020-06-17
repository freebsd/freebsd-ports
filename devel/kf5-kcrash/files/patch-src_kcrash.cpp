Obtained from:
	https://github.com/KDE/kcrash/commit/a82b949adc1619ad44da002a207073b019865f4b

--- src/kcrash.cpp.orig	2020-06-07 09:24:34 UTC
+++ src/kcrash.cpp
@@ -89,6 +89,8 @@ typedef struct {
 #define LAUNCHER_OK 4
 #define LAUNCHER_EXEC_NEW 12
 
+extern "C" char **environ;
+
 namespace KCrash
 {
 KCRASH_EXPORT bool loadedByKdeinit = false;
@@ -719,7 +721,7 @@ static pid_t startDirectly(const char *argv[])
 #ifndef Q_OS_OSX
         closeAllFDs(); // We are in the child now. Close FDs unconditionally.
 #endif
-        execvpe(argv[0], const_cast< char ** >(argv), const_cast<char**> (environ_data.data()));
+        execve(argv[0], const_cast< char ** >(argv), const_cast<char**> (environ_data.data()));
         fprintf(stderr, "KCrash failed to exec(), errno = %d\n", errno);
         _exit(253);
     default:
