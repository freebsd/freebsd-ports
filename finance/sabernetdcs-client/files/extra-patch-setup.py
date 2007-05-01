--- setup.py.orig	Tue Oct  3 03:09:36 2006
+++ setup.py	Tue May  1 14:43:15 2007
@@ -212,7 +212,7 @@
             packages+=["sndcs_client", "sndcs_client.gtk"]
         else:
             packages+=["sndcs_client", "sndcs_common", "sndcs_client.gtk", "sndcs_client.curses"]
-            data_files+=[ ("%setc/sndcs" % (prefix), ["sndcs/config/logging.conf"]), ("share/pixmaps", ["sndcs/pixmaps/sndcs.png"]), ("share/doc/sndcs/html", glob.glob("./docs/*.html")), ("share/doc/sndcs/pdf", glob.glob("./docs/*.pdf")), ("share/doc/sndcs/txt", glob.glob("./docs/*.txt")), ("share/doc/sndcs", [ "COPYING", "README", "AUTHORS", "ChangeLog", "NEWS"]) ]
+            data_files+=[ ("%setc/sndcs" % (prefix), ["sndcs/config/logging.conf"]), ("share/pixmaps", ["sndcs/pixmaps/sndcs.png"]) ]
         if BUILDING_DEB:
             scripts+=["sndcs_client/gtk/sndcs_gtk"]
         else:
