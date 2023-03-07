--- platform/x11/detect.py.orig	2021-12-21 22:27:28 UTC
+++ platform/x11/detect.py
@@ -338,7 +338,7 @@ def configure(env):
         else:
             print("Warning: PulseAudio development libraries not found. Disabling the PulseAudio audio driver.")
 
-    if platform.system() == "Linux":
+    if platform.system() in ["Linux","FreeBSD"]:
         env.Append(CPPDEFINES=["JOYDEV_ENABLED"])
         if env["udev"]:
             if os.system("pkg-config --exists libudev") == 0:  # 0 means found
@@ -365,7 +365,7 @@ def configure(env):
     if env["execinfo"]:
         env.Append(LIBS=["execinfo"])
 
-    if not env["tools"]:
+    if not env["tools"] and False: # not building templates, just runtime
         import subprocess
         import re
 
