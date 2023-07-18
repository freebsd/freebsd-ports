--- groups/bal/balst/balst_stacktraceresolverimpl_elf.cpp.orig	2023-08-05 19:22:01 UTC
+++ groups/bal/balst/balst_stacktraceresolverimpl_elf.cpp
@@ -51,7 +51,7 @@ BSLS_IDENT_RCSID(balst_stacktraceresolverimpl_elf_cpp,
 # define u_DWARF 1
 #endif
 
-#if defined(BSLS_PLATFORM_OS_LINUX)
+#if defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_FREEBSD)
 
 # include <cxxabi.h>
 # include <dlfcn.h>
@@ -4017,7 +4017,7 @@ void u::StackTraceResolver::setFrameSymbolName(
 #endif
 }
 
-#if defined(BSLS_PLATFORM_OS_LINUX)
+#if defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_FREEBSD)
 // Linux could use the same method as Solaris, but we would need a special case
 // for statically linked apps.  Instead of that we're going to use the
 // 'dl_iterate_phdr' function, which works for static and dynamic apps (you get
@@ -4088,7 +4088,7 @@ int u::StackTraceResolver::resolve(
         return 0;                                                     // RETURN
     }
 
-#if defined(BSLS_PLATFORM_OS_LINUX)
+#if defined(BSLS_PLATFORM_OS_LINUX) || defined(BSLS_PLATFORM_OS_FREEBSD)
 
     u::StackTraceResolver resolver(stackTrace,
                                        demanglingPreferredFlag);
