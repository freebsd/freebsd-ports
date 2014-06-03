--- lib/util.py.orig	2014-03-16 12:12:20.000000000 +0100
+++ lib/util.py	2014-06-03 11:13:22.956308357 +0200
@@ -58,10 +58,11 @@
     elif platform.system() == "Linux":
         return os.path.join(sys.prefix, "share", "electrum")
     elif (platform.system() == "Darwin" or
+          platform.system() == "FreeBSD" or
           platform.system() == "DragonFly" or
           platform.system() == "OpenBSD" or
 	  platform.system() == "NetBSD"):
-        return "/Library/Application Support/Electrum"
+	return os.path.join('%%PREFIX%%', "share", "electrum")
     else:
         raise Exception("Unknown system")
 
