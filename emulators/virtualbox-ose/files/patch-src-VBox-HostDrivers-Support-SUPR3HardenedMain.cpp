--- src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp	(revision 25471)
+++ src/VBox/HostDrivers/Support/SUPR3HardenedMain.cpp	(revision 25472)
@@ -66,6 +66,9 @@
 #  ifndef CAP_TO_MASK
 #   define CAP_TO_MASK(cap) RT_BIT(cap)
 #  endif
+# elif defined(RT_OS_FREEBSD)
+#  include <sys/param.h>
+#  include <sys/sysctl.h>
 # elif defined(RT_OS_SOLARIS)
 #  include <priv.h>
 # endif
@@ -325,7 +328,19 @@
     sprintf(szFileBuf, "/proc/%ld/path/a.out", (long)getpid());
     int cchLink = readlink(szFileBuf, &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
 # else /* RT_OS_FREEBSD: */
-    int cchLink = readlink("/proc/curproc/file", &g_szSupLibHardenedExePath[0], sizeof(g_szSupLibHardenedExePath) - 1);
+    int aiName[4];
+    size_t cbPath;
+
+    aiName[0] = CTL_KERN;
+    aiName[1] = KERN_PROC;
+    aiName[2] = KERN_PROC_PATHNAME;
+    aiName[3] = getpid();
+
+    cbPath = sizeof(g_szSupLibHardenedExePath) - 1;
+    if(sysctl(aiName, RT_ELEMENTS(aiName), g_szSupLibHardenedExePath, &cbPath, NULL, 0) < 0)
+       supR3HardenedFatal("supR3HardenedExecDir: sysctl failed\n");
+
+    int cchLink = strlen(g_szSupLibHardenedExePath);
 # endif
     if (cchLink < 0 || cchLink == sizeof(g_szSupLibHardenedExePath) - 1)
         supR3HardenedFatal("supR3HardenedExecDir: couldn't read \"%s\", errno=%d cchLink=%d\n",
