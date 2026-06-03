--- pxr/base/arch/debugger.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/debugger.cpp
@@ -14,7 +14,7 @@
 #include "pxr/base/arch/export.h"
 #include "pxr/base/arch/stackTrace.h"
 #include "pxr/base/arch/systemInfo.h"
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #include "pxr/base/arch/inttypes.h"
 #include <sys/types.h>
 #if !defined(ARCH_OS_IPHONE)
@@ -60,7 +60,7 @@ static char** _archDebuggerAttachArgs = 0;
 
 static char** _archDebuggerAttachArgs = 0;
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerTrapHandler(int)
@@ -75,7 +75,7 @@ Arch_DebuggerTrapHandler(int)
 }
 #endif
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerInitPosix()
@@ -109,7 +109,7 @@ Arch_DebuggerInit()
 void
 Arch_DebuggerInit()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #if defined(ARCH_CPU_INTEL) && defined(ARCH_BITS_64)
     // Save some registers that normally don't have to be preserved.  We
     // do this so the caller of ArchDebuggerTrap() can see its arguments
@@ -154,7 +154,7 @@ Arch_DebuggerInit()
 }
 
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 // Use a 'non-locking' fork so that we won't get hung up if we've
 // had malloc corruption.  We can't prevent fork() from using the
 // heap, unfortunately, since fork handlers can do whatever they
@@ -339,7 +339,7 @@ Arch_DebuggerAttachExecPosix(void* data)
 
 #endif // defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
 // Reads /proc/self/status, finds the line starting with "field:", and
 // returns the portion following the ":".
@@ -450,7 +450,7 @@ Arch_DebuggerAttach()
         return false;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 
     // To attach to gdb under Unix/Linux and Gnome:
     //   ARCH_DEBUGGER="gnome-terminal -e 'gdb -p %p'"
@@ -507,7 +507,7 @@ Arch_InitDebuggerAttach()
 void
 Arch_InitDebuggerAttach()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     // Maximum length of a pid written as a decimal.  It's okay for this
     // to be greater than that.
     static const size_t _decimalPidLength = 20;
@@ -639,7 +639,7 @@ ArchDebuggerIsAttached()
     return IsDebuggerPresent() == TRUE;
 #elif defined(ARCH_OS_DARWIN)
     return AmIBeingDebugged();
-#elif defined(ARCH_OS_LINUX)
+#elif defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     return Arch_DebuggerIsAttachedPosix();
 #endif
     return false;
