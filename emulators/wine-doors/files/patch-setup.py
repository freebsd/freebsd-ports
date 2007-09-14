--- setup.py.orig	Fri Jul 13 20:24:48 2007
+++ setup.py	Fri Jul 13 20:29:51 2007
@@ -89,24 +89,14 @@
         if argument.startswith( "-S" ):
             sysinstall = True
 
-    if sysinstall:
-        final = prefix
-        prefix = temp + prefix
-        prefix_bin = prefix + "/usr/bin/"
-        prefix_data = prefix + "/usr/share/"
-        prefix_conf = prefix + "/etc/" + wine_doors + "/"
-        winedoors_data = prefix_data + wine_doors + "/"
-
-        final_data = final + "usr/share/wine-doors/"
-        final_conf = prefix_conf
-    else:
-        prefix_bin = prefix + "bin/"
-        prefix_data = prefix + ".local/share/"
-        prefix_conf = prefix + ".wine/wine-doors/"
-        winedoors_data = prefix_data + wine_doors + "/"
-
-        final_data = winedoors_data
-        final_conf = prefix_conf
+    prefix = "%%PREFIX%%/"
+    prefix_bin = prefix + "bin/"
+    prefix_data = prefix + "share/"
+    prefix_conf = prefix + "etc/wine-doors/"
+    winedoors_data = prefix_data + "wine-doors/"
+    final = prefix
+    final_data = winedoors_data
+    final_conf = prefix_conf
     
     if command in ("install", "uninstall"):
         from preferences import preferences
@@ -198,7 +188,7 @@
         # Fix perms
         if sysinstall:
             print "Setting permissions"
-            os.system( "chmod og+r -R "+winedoors_data )
+            os.system( "chmod -R og+r "+winedoors_data )
         
         # Write preferences.xml
         print "Creating initial preferences"
