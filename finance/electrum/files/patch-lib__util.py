--- ./lib/util.py.orig	2013-04-07 21:30:06.000000000 +0900
+++ ./lib/util.py	2013-06-09 19:36:01.945732000 +0900
@@ -59,8 +59,10 @@
         return os.path.join(os.environ["APPDATA"], "Electrum")
     elif platform.system() == "Linux":
         return os.path.join(sys.prefix, "share", "electrum")
+    elif (sys.platform.startswith("dragonfly") or
+          sys.platform.startswith("freebsd")):
+	return os.path.join('%%PREFIX%%', "share", "electrum")
     elif (platform.system() == "Darwin" or
-          platform.system() == "DragonFly" or
 	  platform.system() == "NetBSD"):
         return "/Library/Application Support/Electrum"
     else:
