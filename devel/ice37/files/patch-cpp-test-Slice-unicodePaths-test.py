--- cpp/test/Slice/unicodePaths/test.py.orig	2018-08-27 01:10:47 UTC
+++ cpp/test/Slice/unicodePaths/test.py
@@ -14,7 +14,7 @@ class SliceUnicodePathsTestCase(ClientTe
 
     def runClientSide(self, current):
 
-        if isinstance(platform, Linux) or isinstance(platform, AIX):
+        if isinstance(platform, Linux) or isinstance(platform, AIX) or isinstance(platform, FreeBSD):
             encoding = locale.getdefaultlocale()[1]
             if encoding != "UTF-8":
                 current.writeln("Please set LC_ALL to xx_xx.UTF-8, for example FR_FR.UTF-8")
