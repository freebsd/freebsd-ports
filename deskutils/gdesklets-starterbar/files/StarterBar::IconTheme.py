--- StarterBar/IconTheme.py.orig	Sun Nov  9 16:15:19 2003
+++ StarterBar/IconTheme.py	Sun Nov  9 16:15:54 2003
@@ -145,7 +145,7 @@
            commands.getstatusoutput(self.__PREFIX)
         if (fail): prefix = "/usr"
 
-        path = os.path.join(prefix, "share")
+        path = os.path.join("%%X11BASE%%", "share")
 
 
         dirs = [os.path.join(os.path.expanduser("~"), ".icons"),
