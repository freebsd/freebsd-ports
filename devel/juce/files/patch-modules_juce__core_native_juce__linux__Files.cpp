- workaround for https://reviews.freebsd.org/D30842

--- modules/juce_core/native/juce_linux_Files.cpp.orig	2022-10-16 19:17:29 UTC
+++ modules/juce_core/native/juce_linux_Files.cpp
@@ -229,7 +229,7 @@ bool Process::openDocument (const String& fileName, co
         setsid();
 
         // Child process
-        execve (argv[0], (char**) argv, environ);
+        execv (argv[0], (char**) argv);
         exit (0);
     }
 
