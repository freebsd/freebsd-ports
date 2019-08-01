--- cpp/extlibs/greenlet/slp_platformselect.h.orig	2019-07-26 21:28:17 UTC
+++ cpp/extlibs/greenlet/slp_platformselect.h
@@ -8,7 +8,7 @@
 #include "switch_amd64_unix.h" /* gcc on amd64 */
 #elif defined(__GNUC__) && defined(__i386__)
 #include "switch_x86_unix.h" /* gcc on X86 */
-#elif defined(__GNUC__) && defined(__PPC__) && defined(__linux__)
+#elif defined(__GNUC__) && defined(__PPC__) && !defined(__APPLE__)
 #include "switch_ppc_unix.h" /* gcc on PowerPC */
 #elif defined(__GNUC__) && defined(__ppc__) && defined(__APPLE__)
 #include "switch_ppc_macosx.h" /* Apple MacOS X on PowerPC */
