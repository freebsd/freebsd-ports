--- ghc/rts/Linker.c.orig	Tue Dec 16 17:58:26 2003
+++ ghc/rts/Linker.c	Tue Jan 13 16:47:50 2004
@@ -10,6 +10,12 @@
 #if 0
 #include "PosixSource.h"
 #endif
+
+//  Linux needs _GNU_SOURCE to get RTLD_DEFAULT from <dlfcn.h>.
+#ifdef __linux__
+#define _GNU_SOURCE
+#endif
+
 #include "Rts.h"
 #include "RtsFlags.h"
 #include "HsFFI.h"
@@ -694,7 +700,11 @@
 #   endif
 
 #   if defined(OBJFORMAT_ELF) || defined(OBJFORMAT_MACHO)
+#   if defined(RTLD_DEFAULT)
+    dl_prog_handle = RTLD_DEFAULT;
+#   else
     dl_prog_handle = dlopen(NULL, RTLD_LAZY);
+#   endif // RTLD_DEFAULT
 #   endif
 }
 
