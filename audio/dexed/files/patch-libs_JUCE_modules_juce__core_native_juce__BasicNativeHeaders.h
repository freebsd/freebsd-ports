-- Undefine the "mb" macro leaked by FreeBSD's <sys/user.h> (which pulls in
-- machine/atomic.h) on arm/aarch64. That macro collides with local
-- variables/members named "mb" used throughout JUCE.
-- See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283492

--- libs/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2026-09-30 14:06:43 UTC
+++ libs/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -248,6 +248,11 @@
  #include <utime.h>
  #include <poll.h>
 
+ // sys/user.h pulls in machine/atomic.h on FreeBSD/arm, which defines a
+ // function-like macro "mb()" that collides with local variables/members
+ // named "mb" used throughout JUCE, causing build failures.
+ #undef mb
+
 //==============================================================================
 #elif JUCE_ANDROID
  #include <jni.h>
