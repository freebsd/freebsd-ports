--- odoo/tools/_vendor/sessions.py	2021-09-04 18:46:08.432901000 -0500
+++ odoo/tools/_vendor/sessions.py	2021-09-04 18:46:25.423822000 -0500
@@ -26,7 +26,6 @@
 from time import time
 
 from werkzeug.datastructures import CallbackDict
-from werkzeug.posixemulation import rename
 
 _sha1_re = re.compile(r"^[a-f0-9]{40}$")
 
@@ -198,7 +197,7 @@
         finally:
             f.close()
         try:
-            rename(tmp, fn)
+            os.rename(tmp, fn)
             os.chmod(fn, self.mode)
         except (IOError, OSError):
             pass
