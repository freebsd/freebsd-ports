--- setup.py.orig	Tue Jun  8 12:15:26 2004
+++ setup.py	Tue Jun  8 12:15:08 2004
@@ -18,7 +18,7 @@
      libpath = r"lib\site-packages\kodos"
 else:
      #libpath = "/usr/local/kodos" # 2.4.0 and prior
-     libpath = "/usr/share/kodos"  # as of 2.4.1
+     libpath = "%%PREFIX%%/share/kodos"  # as of 2.4.1
 
 for arg in args:
     if arg == "--formats=wininst":
