--- install.py.orig	2008-07-08 15:03:56.000000000 -0500
+++ install.py	2008-07-08 15:04:27.000000000 -0500
@@ -181,8 +181,8 @@
         print "Updated mime database."
         schemas = \
             no_balloon and "comicbook-no-balloon.schemas" or "comicbook.schemas"
-        os.popen("export GCONF_CONFIG_SOURCE=`gconftool-2 "
-                 "--get-default-source 2>/dev/null` && gconftool-2 "
+        os.popen("export GCONF_CONFIG_SOURCE=%%GCONF_CONFIG_SOURCE%% "
+                 "&& gconftool-2 "
                  "--makefile-install-rule ./mime/%s 2>/dev/null" % schemas)
         print
         print "Registered comic archive thumbnailer in gconf (if available)."
