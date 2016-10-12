--- python/test/Slice/unicodePaths/run.py.orig	2016-10-05 16:59:08.000000000 +0200
+++ python/test/Slice/unicodePaths/run.py	2016-10-12 12:00:24.045889876 +0200
@@ -26,7 +26,7 @@
         print("failed!")
         sys.exit(1)
 
-if TestUtil.isAIX() or TestUtil.isLinux():
+if TestUtil.isAIX() or TestUtil.isLinux() or TestUtil.isFreeBSD():
     encoding = locale.getdefaultlocale()[1]
     if encoding != "UTF-8":
         print("Please set LC_ALL to xx_xx.UTF-8, for example FR_FR.UTF-8")
