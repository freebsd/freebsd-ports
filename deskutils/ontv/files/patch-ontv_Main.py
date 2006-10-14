--- ontv/Main.py.orig	Mon Jul 24 23:09:57 2006
+++ ontv/Main.py	Mon Jul 24 23:10:06 2006
@@ -38,8 +38,8 @@
     gettext.bindtextdomain(NAME.lower(), LOCALE_DIR)
     gettext.textdomain(NAME.lower())
 
-    locale.bindtextdomain(NAME.lower(), LOCALE_DIR)
-    locale.textdomain(NAME.lower())
+#    locale.bindtextdomain(NAME.lower(), LOCALE_DIR)
+#    locale.textdomain(NAME.lower())
 
     try:
         opts, args = getopt.getopt(sys.argv[1:], "hdw", ["help", "debug",
