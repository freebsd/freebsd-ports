--- swift-corelibs-foundation/lib/target.py.orig	2017-04-13 07:34:00 UTC
+++ swift-corelibs-foundation/lib/target.py
@@ -204,6 +204,8 @@ class ArchType:
             return ArchType.x86
         if string == "x86_64":
             return ArchType.x86_64
+        if string == "amd64":
+            return ArchType.x86_64
         if string == "xcore":
             return ArchType.xcore
         if string == "nvptx":
@@ -370,7 +372,7 @@ class Target:
             triple += "-apple-darwin"
         elif platform.system() == "FreeBSD":
             # Make this work on 10 as well.
-            triple += "-freebsd11.0"
+            triple += "-v11.0-freebsd11.0"
         elif platform.system() == "CYGWIN_NT-10.0":
             triple += "-windows-cygnus"
         else:
