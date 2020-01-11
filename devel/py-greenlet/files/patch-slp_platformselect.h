--- slp_platformselect.h.orig	2020-01-10 10:02:27 UTC
+++ slp_platformselect.h
@@ -12,7 +12,7 @@
 #include "platform/switch_amd64_unix.h" /* gcc on amd64 */
 #elif defined(__GNUC__) && defined(__i386__)
 #include "platform/switch_x86_unix.h" /* gcc on X86 */
-#elif defined(__GNUC__) && defined(__powerpc64__) && defined(__linux__)
+#elif defined(__GNUC__) && defined(__powerpc64__) && (defined(__linux__) || defined(__FreeBSD__))
 #include "platform/switch_ppc64_linux.h" /* gcc on PowerPC 64-bit */
 #elif defined(__GNUC__) && defined(__PPC__) && defined(__linux__)
 #include "platform/switch_ppc_linux.h" /* gcc on PowerPC */
