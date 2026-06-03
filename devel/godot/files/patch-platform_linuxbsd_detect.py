--- platform/linuxbsd/detect.py.orig	2025-10-13 19:05:40 UTC
+++ platform/linuxbsd/detect.py
@@ -382,7 +382,7 @@ def configure(env: "SConsEnvironment"):
     else:
         env.Append(CPPDEFINES=["XKB_ENABLED"])
 
-    if platform.system() == "Linux":
+    if platform.system() in ["Linux", "FreeBSD"]:
         if env["udev"]:
             if not env["use_sowrap"]:
                 if os.system("pkg-config --exists libudev") == 0:  # 0 means found
@@ -395,13 +395,17 @@ def configure(env: "SConsEnvironment"):
                 env.Append(CPPDEFINES=["UDEV_ENABLED"])
     else:
         env["udev"] = False  # Linux specific
-
+    
     if env["sdl"]:
         if env["builtin_sdl"]:
             env.Append(CPPDEFINES=["SDL_ENABLED"])
+            if platform.system() in ["FreeBSD", "OpenBSD", "NetBSD"]:
+                env["LINKCOM"] += " -l:libusbhid.a"
         elif os.system("pkg-config --exists sdl3") == 0:  # 0 means found
             env.ParseConfig("pkg-config sdl3 --cflags --libs")
             env.Append(CPPDEFINES=["SDL_ENABLED"])
+            if platform.system() in ["FreeBSD", "OpenBSD", "NetBSD"]:
+                env.Append(LIBS=["usbhid"])
         else:
             print_warning(
                 "SDL3 development libraries not found, and `builtin_sdl` was explicitly disabled. Disabling SDL input driver support."
@@ -484,7 +488,9 @@ def configure(env: "SConsEnvironment"):
             env.Append(CPPDEFINES=["LIBDECOR_ENABLED"])
 
         env.Append(CPPDEFINES=["WAYLAND_ENABLED"])
-        env.Append(LIBS=["rt"])  # Needed by glibc, used by _allocate_shm_file
+        # FreeBSD and OpenBSD keep rt functionality in libc
+        if platform.system() in ["Linux", "NetBSD"]:
+            env.Append(LIBS=["rt"])  # Needed by glibc, used by _allocate_shm_file
 
     if env["accesskit"]:
         if env["accesskit_sdk_path"] != "":
@@ -517,7 +523,7 @@ def configure(env: "SConsEnvironment"):
 
     env.Append(LIBS=["pthread"])
 
-    if platform.system() == "Linux":
+    if platform.system() in ["Linux", "FreeBSD"]:
         env.Append(LIBS=["dl"])
 
     if platform.libc_ver()[0] != "glibc":
@@ -536,9 +542,17 @@ def configure(env: "SConsEnvironment"):
 
     # Link those statically for portability
     if env["use_static_cpp"]:
-        env.Append(LINKFLAGS=["-static-libgcc", "-static-libstdc++"])
-        if env["use_llvm"] and platform.system() != "FreeBSD":
-            env["LINKCOM"] = env["LINKCOM"] + " -l:libatomic.a"
+        # TODO Test NetBSD clang, guessing that it also does not support -static-libstdc++? Does its libc++ have other deps?
+        if env["use_llvm"] and platform.system() in ["FreeBSD", "OpenBSD", "NetBSD"]:
+            env.Append(LINKFLAGS=["-nostdlib++"])
+            env["LINKCOM"] += " -l:libc++.a"
+            if platform.system() == "OpenBSD":
+                env["LINKCOM"] += " -l:libc++abi.a"
+        else:
+            env.Append(LINKFLAGS=["-static-libgcc", "-static-libstdc++"])
+
+        if env["use_llvm"] and platform.system() not in ["FreeBSD", "OpenBSD", "NetBSD"]:
+            env["LINKCOM"] += " -l:libatomic.a"
     else:
-        if env["use_llvm"] and platform.system() != "FreeBSD":
+        if env["use_llvm"] and platform.system() not in ["FreeBSD", "OpenBSD", "NetBSD"]:
             env.Append(LIBS=["atomic"])
