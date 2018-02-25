--- Mailman/Utils.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/Utils.py
@@ -93,6 +93,12 @@ def list_exists(listname):
     #
     # The former two are for 2.1alpha3 and beyond, while the latter two are
     # for all earlier versions.
+    #
+    # But first ensure the list name doesn't contain a path traversal
+    # attack.
+    if len(re.sub(mm_cfg.ACCEPTABLE_LISTNAME_CHARACTERS, '', listname)) > 0:
+        syslog('mischief', 'Hostile listname: %s', listname)
+        return False
     basepath = Site.get_listpath(listname)
     for ext in ('.pck', '.pck.last', '.db', '.db.last'):
         dbfile = os.path.join(basepath, 'config' + ext)
