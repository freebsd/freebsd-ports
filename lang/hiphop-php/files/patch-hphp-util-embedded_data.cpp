--- hphp/util/embedded_data.cpp.orig	2013-07-22 20:35:04.724464109 +0200
+++ hphp/util/embedded_data.cpp	2013-07-22 20:44:41.416725106 +0200
@@ -27,12 +27,43 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <limits.h>
+#include <sys/sysctl.h>
+#endif
+
 #ifdef __APPLE__
 #include <mach-o/getsect.h>
 #endif
 
 namespace HPHP { namespace Util {
 
+#ifdef __FreeBSD__
+static int
+_get_exepath(char *buffer, size_t *size) {
+  int mib[4];
+  size_t cb;
+
+  if (!buffer || !size) {
+    return (-1);
+  }
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PATHNAME;
+  mib[3] = -1;
+
+  cb = *size;
+  if (sysctl(mib, 4, buffer,  &cb, NULL, 0) < 0) {
+    *size = 0;
+    return (-1);
+  }
+  *size = strlen(buffer);
+
+  return(0);
+}
+#endif
+
 bool get_embedded_data(const char *section, embedded_data* desc) {
 #ifndef __APPLE__
   GElf_Shdr shdr;
@@ -42,7 +73,19 @@
 
   if (elf_version(EV_CURRENT) == EV_NONE) return false;
 
+#ifdef __FreeBSD__
+  char exepath[PATH_MAX];
+  size_t exesize;
+
+  exesize = sizeof(exepath);
+  if (_get_exepath(exepath, &exesize) != 0) return false;
+
+  if (exesize < 1) return false;
+
+  int fd = open(exepath, O_RDONLY, 0);
+#else
   int fd = open("/proc/self/exe", O_RDONLY, 0);
+#endif
   if (fd < 0) return false;
   SCOPE_EXIT { close(fd); };
 
@@ -67,7 +110,11 @@
     if (!strcmp(section, name)) {
       GElf_Shdr ghdr;
       if (gelf_getshdr(scn, &ghdr) != &ghdr) return false;
+#ifdef __FreeBSD__
+      desc->m_filename = exepath;
+#else
       desc->m_filename = "/proc/self/exe";
+#endif
       desc->m_start = ghdr.sh_offset;
       desc->m_len = ghdr.sh_size;
       return true;
