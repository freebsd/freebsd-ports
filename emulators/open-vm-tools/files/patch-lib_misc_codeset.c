--- lib/misc/codeset.c.orig	2025-06-19 04:05:18 UTC
+++ lib/misc/codeset.c
@@ -100,7 +100,7 @@
 #   define POSIX_ICU_DIR DEFAULT_LIBDIRECTORY
 #elif !defined _WIN32
 #   if defined(VMX86_TOOLS)
-#      define POSIX_ICU_DIR "/etc/vmware-tools"
+#      define POSIX_ICU_DIR "%%PREFIX%%/etc/vmware-tools"
 #   else
 #      define POSIX_ICU_DIR "/etc/vmware"
 #   endif
