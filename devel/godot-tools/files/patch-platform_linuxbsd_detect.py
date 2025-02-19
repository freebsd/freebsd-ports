--- platform/linuxbsd/detect.py.orig	2025-02-19 15:17:58.330499000 +0100
+++ platform/linuxbsd/detect.py	2025-02-19 15:20:19.837955000 +0100
@@ -370,7 +370,7 @@
     else:
         env.Append(CPPDEFINES=["XKB_ENABLED"])
 
-    if platform.system() == "Linux":
+    if platform.system() in  ["Linux","FreeBSD"]:
         env.Append(CPPDEFINES=["JOYDEV_ENABLED"])
         if env["udev"]:
             if not env["use_sowrap"]:
