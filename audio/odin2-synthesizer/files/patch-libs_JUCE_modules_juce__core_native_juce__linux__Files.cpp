--- libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp.orig	2025-02-22 09:24:02 UTC
+++ libs/JUCE/modules/juce_core/native/juce_linux_Files.cpp
@@ -230,7 +230,7 @@ bool Process::openDocument (const String& fileName, co
         setsid();
 
         // Child process
-        execve (argv[0], (char**) argv, environ);
+        execv (argv[0], (char**) argv);
         exit (0);
     }
 
