Index: src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp
@@ -54,7 +54,8 @@
 #ifdef RT_OS_WINDOWS
 # include <windows.h>
 # include <winioctl.h>
-#elif defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) \
+    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
 # include <errno.h>
 # include <sys/ioctl.h>
 # include <sys/types.h>
@@ -76,6 +77,9 @@
 # include <sys/dkio.h>
 # include <sys/vtoc.h>
 #endif /* RT_OS_SOLARIS */
+#ifdef RT_OS_FREEBSD
+# include <sys/disk.h>
+#endif /* RT_OS_FREEBSD */
 
 using namespace com;
 
@@ -1013,6 +1017,28 @@
         vrc = VERR_INVALID_PARAMETER;
         goto out;
     }
+#elif defined(RT_OS_FREEBSD)
+    struct stat DevStat;
+    if (!fstat(RawFile, &DevStat) && S_ISCHR(DevStat.st_mode))
+    {
+        off_t cMediasize = 0;
+        if (!ioctl(RawFile, DIOCGMEDIASIZE, &cMediasize))
+        {
+            cbSize = cMediasize;
+        }
+        else
+        {
+            vrc = RTErrConvertFromErrno(errno);
+            RTPrintf("Cannot get the block count for file '%s': %Rrc", rawdisk.raw(), vrc);
+            goto out;
+        }
+    }
+    else
+    {
+        RTPrintf("File '%s' is no character device\n", rawdisk.raw());
+        vrc = VERR_INVALID_PARAMETER;
+        goto out;
+    }
 #else /* all unrecognized OSes */
     /* Hopefully this works on all other hosts. If it doesn't, it'll just fail
      * creating the VMDK, so no real harm done. */
