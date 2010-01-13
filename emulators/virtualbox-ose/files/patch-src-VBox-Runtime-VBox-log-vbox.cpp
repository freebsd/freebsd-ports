--- src/VBox/Runtime/VBox/log-vbox.cpp	(revision 25471)
+++ src/VBox/Runtime/VBox/log-vbox.cpp	(revision 25472)
@@ -135,6 +135,12 @@
 #  include <Windows.h>
 # elif defined(RT_OS_LINUX)
 #  include <unistd.h>
+# elif defined(RT_OS_FREEBSD)
+#  include <sys/param.h>
+#  include <sys/sysctl.h>
+#  include <sys/user.h>
+#  include <stdlib.h>
+#  include <unistd.h>
 # elif defined(RT_OS_SOLARIS)
 #  define _STRUCTURED_PROC 1
 #  undef _FILE_OFFSET_BITS /* procfs doesn't like this */
@@ -157,6 +163,7 @@
 # include <iprt/path.h>
 # include <iprt/process.h>
 # include <iprt/string.h>
+# include <iprt/mem.h>
 # include <stdio.h>
 #endif
 
@@ -339,12 +346,8 @@
             fclose(pFile);
         }
 
-#  elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
-#   ifdef RT_OS_LINUX
+#  elif defined(RT_OS_LINUX)
         FILE *pFile = fopen("/proc/self/cmdline", "r");
-#   else /* RT_OS_FREEBSD: */
-        FILE *pFile = fopen("/proc/curproc/cmdline", "r");
-#   endif
         if (pFile)
         {
             /* braindead */
@@ -370,7 +373,44 @@
                 RTLogLoggerEx(pLogger, 0, ~0U, "\n");
             fclose(pFile);
         }
+#  elif defined(RT_OS_FREEBSD)
+        char *pszArgFileBuf = NULL;
+        int aiName[4];
+        size_t cchArgs;
 
+        aiName[0] = CTL_KERN;
+        aiName[1] = KERN_PROC;
+        aiName[2] = KERN_PROC_ARGS;
+        aiName[3] = -1;
+
+        /* Retrieve the required length first */
+        cchArgs = 0;
+        int rcBSD = sysctl(aiName, RT_ELEMENTS(aiName), NULL, &cchArgs, NULL, 0);
+
+        if (cchArgs > 0)
+        {
+            pszArgFileBuf = (char *)RTMemAllocZ(cchArgs + 1 /* Safety */);
+            if (pszArgFileBuf)
+            {
+                /* Retrieve the argument list */
+                rcBSD = sysctl(aiName, RT_ELEMENTS(aiName), pszArgFileBuf, &cchArgs, NULL, 0);
+                if (!rcBSD)
+                {
+                    /*
+                     * cmdline is a flattened argument list so we need
+                     * to convert all \0 to blanks
+                     */
+                    for(size_t i = 0; i < cchArgs - 1; i++)
+                    {
+                       if(pszArgFileBuf[i] == '\0')
+                          pszArgFileBuf[i] = ' ';
+                    }
+
+                    RTLogLoggerEx(pLogger, 0, ~0U, "Commandline: %s\n", pszArgFileBuf);
+                }
+                RTMemFree(pszArgFileBuf);
+            }
+        }
 #  elif defined(RT_OS_L4) || defined(RT_OS_OS2) || defined(RT_OS_DARWIN)
         /* commandline? */
 #  else
