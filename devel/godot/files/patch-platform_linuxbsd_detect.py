--- platform/linuxbsd/detect.py.orig	2025-03-25 23:11:16 UTC
+++ platform/linuxbsd/detect.py
@@ -373,7 +373,7 @@ def configure(env: "SConsEnvironment"):
     else:
         env.Append(CPPDEFINES=["XKB_ENABLED"])
 
-    if platform.system() == "Linux":
+    if platform.system() in  ["Linux","FreeBSD"]:
         env.Append(CPPDEFINES=["JOYDEV_ENABLED"])
         if env["udev"]:
             if not env["use_sowrap"]:
