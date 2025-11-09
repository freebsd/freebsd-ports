--- tools/gn/src/util/exe_path.cc.orig	2022-02-07 13:39:41 UTC
+++ tools/gn/src/util/exe_path.cc
@@ -15,7 +15,7 @@
 #include <windows.h>
 
 #include "base/win/win_util.h"
-#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD)
 #include <limits.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -26,6 +26,10 @@
 #include <stdlib.h>
 #endif
 
+#if defined(OS_OPENBSD)
+#include <kvm.h>
+#endif
+
 #if defined(OS_MACOSX)
 
 base::FilePath GetExePath() {
@@ -102,6 +106,67 @@ base::FilePath GetExePath() {
     return base::FilePath();
   }
   return base::FilePath(raw);
+}
+
+#elif defined(OS_OPENBSD)
+
+base::FilePath GetExePath() {
+  struct kinfo_file *files;
+  kvm_t *kd = NULL;
+  char errbuf[_POSIX2_LINE_MAX];
+  char **retvalargs;
+#define MAXTOKENS 2
+  char *tokens[MAXTOKENS];
+  static char retval[PATH_MAX];
+  int cnt;
+  size_t len;
+  struct stat sb;
+  pid_t cpid = getpid();
+
+  int mib[] = { CTL_KERN, KERN_PROC_ARGS, cpid, KERN_PROC_ARGV };
+
+  if (sysctl(mib, 4, NULL, &len, NULL, 0) != -1) {
+    retvalargs = static_cast<char**>(malloc(len));
+    if (!retvalargs)
+      goto out;
+
+    if (sysctl(mib, 4, retvalargs, &len, NULL, 0) < 0)
+      goto out;
+
+    char *cr = strdup(retvalargs[0]);
+    free(retvalargs);
+
+    *tokens = strtok(cr, ":");
+    if (tokens[0] == NULL)
+      goto out;
+
+    if (realpath(tokens[0], retval) == NULL)
+      goto out;
+
+    if (stat(retval, &sb) < 0)
+      goto out;
+
+    if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf)) == NULL)
+      goto out;
+
+    if ((files = kvm_getfiles(kd, KERN_FILE_BYPID, cpid,
+                              sizeof(struct kinfo_file), &cnt)) == NULL) {
+      kvm_close(kd); 
+      goto out;
+    }
+
+    for (int i = 0; i < cnt; i++) {
+      if (files[i].fd_fd == KERN_FILE_TEXT &&
+          files[i].va_fsid == static_cast<uint32_t>(sb.st_dev) &&
+          files[i].va_fileid == sb.st_ino) {
+        kvm_close(kd);
+        return base::FilePath(retval);
+      }
+    }
+  }
+
+out:
+  return base::FilePath();
 }
 
 #elif defined(OS_ZOS)
