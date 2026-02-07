--- src/JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2023-02-22 01:49:53 UTC
+++ src/JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -43,7 +43,7 @@
  #else
   #import <Cocoa/Cocoa.h>
   #import <CoreAudio/HostTime.h>
-  #include <sys/dir.h>
+  //#include <sys/dir.h>
  #endif
 
  #include <sys/socket.h>
@@ -172,9 +172,9 @@
  #include <sys/time.h>
  #include <errno.h>
  #include <sys/stat.h>
- #include <sys/dir.h>
+ //#include <sys/dir.h>
  #include <sys/ptrace.h>
- #include <sys/vfs.h>
+ //#include <sys/vfs.h>
  #include <sys/wait.h>
  #include <sys/mman.h>
  #include <fnmatch.h>
@@ -191,9 +191,13 @@
  #include <net/if.h>
  #include <sys/sysinfo.h>
  #include <sys/file.h>
- #include <sys/prctl.h>
+ //#include <sys/prctl.h>
  #include <signal.h>
  #include <stddef.h>
+
+ #include <sys/param.h>
+ #include <sys/mount.h>
+
 
 //==============================================================================
 #elif JUCE_ANDROID
