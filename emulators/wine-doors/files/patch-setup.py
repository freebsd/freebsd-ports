--- setup.py.orig	Mon Feb 18 18:49:23 2008
+++ setup.py	Mon Feb 18 19:08:38 2008
@@ -75,24 +75,18 @@
     if os.getuid() == 0:
         sysinstall = True
 
-    if sysinstall:
-        if not install_root:
-            install_root = "/"
-        if not prefix:
-            prefix = install_root + "usr/"
-        bin_path = prefix + "bin/"
-        data_path = prefix + "share/"
-        conf_path = install_root + "etc/" + wine_doors + "/"
-        winedoors_path = data_path + wine_doors + "/"
-        real_winedoors_path = "/usr/share/"+wine_doors+"/"
-    else:
-        install_root = os.path.expanduser( "~/")
-        prefix = os.path.expanduser( "~/.local" )
-        bin_path = install_root + "bin/"
-        data_path = prefix + "share/"
-        conf_path = os.getenv('WINEPREFIX', install_root + ".wine") + "/wine-doors"
-        winedoors_path = data_path + wine_doors + "/"
-        real_winedoors_path = winedoors_path
+    if prefix == None:
+        print "You must provide a --prefix"
+        sys.exit(1)
+
+    if not prefix.endswith("/"):
+        prefix = prefix + "/"
+
+    bin_path = prefix + "bin/"
+    data_path = prefix + "share/"
+    conf_path = prefix + "etc/" + wine_doors + "/"
+    winedoors_path = data_path + wine_doors + "/"
+    real_winedoors_path = winedoors_path
 
     if command in ("install", "uninstall"):
         from preferences import preferences
@@ -208,7 +202,7 @@
         # Fix perms
         if sysinstall:
             print "Setting permissions"
-            os.system( "chmod og+r -R "+winedoors_path )
+            os.system( "chmod -R og+r "+winedoors_path )
         
         # Write preferences.xml
         print "Creating initial preferences"
