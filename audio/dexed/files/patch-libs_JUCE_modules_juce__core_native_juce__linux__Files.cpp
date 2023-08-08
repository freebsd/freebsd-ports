- otherwise it fails with unknown 'environ' symbol, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=263265

--- libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp.orig	2022-08-15 18:29:17 UTC
+++ libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp
@@ -21,7 +21,9 @@
 */
 
 #if JUCE_BSD
-extern char** environ;
+//extern char** environ; // this is broken on FreeBSD, see https://reviews.freebsd.org/D30842
+#include <dlfcn.h>
+static char*** environ_ptr = (char***)dlsym(RTLD_DEFAULT, "environ"); // workaround for the above
 #endif
 
 namespace juce
@@ -229,7 +231,7 @@ bool Process::openDocument (const String& fileName, co
         setsid();
 
         // Child process
-        execve (argv[0], (char**) argv, environ);
+        execve (argv[0], (char**) argv, *environ_ptr);
         exit (0);
     }
 
