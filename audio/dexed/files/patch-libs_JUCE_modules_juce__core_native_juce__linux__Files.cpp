- otherwise it fails with unknown 'environ' symbol, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=263265

--- libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp.orig	2022-04-13 18:55:08 UTC
+++ libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp
@@ -21,7 +21,7 @@
 */
 
 #if JUCE_BSD
-extern char** environ;
+//extern char** environ;
 #endif
 
 namespace juce
@@ -230,7 +230,7 @@ bool Process::openDocument (const String& fileName, co
         setsid();
 
         // Child process
-        execve (argv[0], (char**) argv, environ);
+        execv (argv[0], (char**) argv);
         exit (0);
     }
 
