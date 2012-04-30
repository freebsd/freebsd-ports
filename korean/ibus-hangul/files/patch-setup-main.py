--- setup/main.py.orig	2012-04-15 10:46:37.000000000 -0400
+++ setup/main.py	2012-04-30 17:57:09.000000000 -0400
@@ -191,8 +191,8 @@
         return self.__config.set_value("engine/Hangul", name, v)
 
 if __name__ == "__main__":
-    locale.bindtextdomain(config.gettext_package, config.localedir)
-    locale.bind_textdomain_codeset(config.gettext_package, "UTF-8")
+    gettext.bindtextdomain(config.gettext_package, config.localedir)
+    gettext.bind_textdomain_codeset(config.gettext_package, "UTF-8")
 
     try:
         bus = ibus.Bus()
