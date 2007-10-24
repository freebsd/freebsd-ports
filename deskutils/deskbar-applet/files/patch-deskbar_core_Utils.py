--- deskbar/core/Utils.py.orig	2007-08-13 13:07:20.000000000 -0400
+++ deskbar/core/Utils.py	2007-08-14 14:35:19.000000000 -0400
@@ -51,7 +51,7 @@ def get_xdg_data_dirs():
     
     sysdirs = os.getenv("XDG_DATA_DIRS")
     if sysdirs == None:
-        sysdirs = "/usr/local/share:/usr/share"
+        sysdirs = "/usr/local/share"
     
     dirs = "%s:%s" % (dirs, sysdirs)
     return [dir for dir in dirs.split(":") if dir.strip() != "" and exists(dir)]
