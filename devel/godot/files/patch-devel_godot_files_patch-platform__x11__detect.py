--- devel/godot/files/patch-platform_x11_detect.py.orig	2020-12-17 13:47:23 UTC
+++ devel/godot/files/patch-platform_x11_detect.py
@@ -0,0 +1,11 @@
+--- platform/x11/detect.py.orig        2020-10-30 01:48:18 UTC
++++ platform/x11/detect.py
+@@ -311,7 +311,7 @@ def configure(env):
+         else:
+             print("PulseAudio development libraries not found, disabling driver")
+ 
+-    if platform.system() == "Linux":
++    if platform.system() == "FreeBSD":
+         env.Append(CPPDEFINES=["JOYDEV_ENABLED"])
+ 
+         if env["udev"]:
