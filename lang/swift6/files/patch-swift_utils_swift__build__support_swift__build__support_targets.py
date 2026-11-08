--- swift/utils/swift_build_support/swift_build_support/targets.py.orig	2026-10-10 18:48:34 UTC
+++ swift/utils/swift_build_support/swift_build_support/targets.py
@@ -290,7 +290,7 @@
         "riscv64",
         "s390x"])
 
-    FreeBSD = Platform("freebsd", archs=["x86_64", "aarch64"])
+    FreeBSD = Platform("freebsd", archs=["x86_64", "aarch64", "powerpc64le"])
 
     LinuxStatic = Platform('linux-static', sdk_name='LINUX_STATIC', archs=[
         'x86_64',
@@ -400,6 +400,8 @@
                 return StdlibDeploymentTarget.FreeBSD.x86_64
             elif machine == 'arm64':
                 return StdlibDeploymentTarget.FreeBSD.aarch64
+            elif machine == 'powerpc' and platform.processor() == 'powerpc64le':
+                return StdlibDeploymentTarget.FreeBSD.powerpc64le
 
         elif system == 'OpenBSD':
             if machine == 'amd64':
