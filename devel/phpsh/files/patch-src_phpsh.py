--- src/phpsh.py.orig
+++ src/phpsh.py
@@ -274,7 +274,7 @@
         self.config.add_section("Emacs")
 
     def read(self):
-        config_files = ["/etc/phpsh/config"]
+        config_files = ["%%ETCDIR%%/config"]
         home = os.getenv("HOME")
         if home:
             homestr = home.strip()
