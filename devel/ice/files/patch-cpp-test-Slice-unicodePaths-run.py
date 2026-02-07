--- cpp/test/Slice/unicodePaths/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Slice/unicodePaths/run.py
@@ -26,7 +26,7 @@ def test(b):
         print("failed!")
         sys.exit(1)
 
-if TestUtil.isAIX() or TestUtil.isLinux():
+if TestUtil.isAIX() or TestUtil.isLinux() or TestUtil.isFreeBSD():
     encoding = locale.getdefaultlocale()[1]
     if encoding != "UTF-8":
         print("Please set LC_ALL to xx_xx.UTF-8, for example FR_FR.UTF-8")
