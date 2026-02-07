--- swift/utils/swift_build_support/swift_build_support/targets.py.orig	2024-06-06 04:26:30 UTC
+++ swift/utils/swift_build_support/swift_build_support/targets.py
@@ -278,7 +278,7 @@ class StdlibDeploymentTarget(object):
         "riscv64",
         "s390x"])
 
-    FreeBSD = Platform("freebsd", archs=["x86_64", "arm64"])
+    FreeBSD = Platform("freebsd", archs=["x86_64", "aarch64"])
 
     OpenBSD = OpenBSDPlatform("openbsd", archs=["amd64"])
 
@@ -379,7 +379,7 @@ class StdlibDeploymentTarget(object):
             if machine == 'amd64':
                 return StdlibDeploymentTarget.FreeBSD.x86_64
             elif machine == 'arm64':
-                return StdlibDeploymentTarget.FreeBSD.arm64
+                return StdlibDeploymentTarget.FreeBSD.aarch64
 
         elif system == 'OpenBSD':
             if machine == 'amd64':
