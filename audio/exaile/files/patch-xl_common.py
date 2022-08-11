https://github.com/exaile/exaile/issues/770

--- xl/common.py.orig	2021-03-28 10:31:17 UTC
+++ xl/common.py
@@ -44,7 +44,12 @@ import weakref
 import urllib.request
 import weakref
 
-import bsddb3 as bsddb
+# TODO: Flip these around once we've done more testing with berkeleydb
+try:
+    import bsddb3 as bsddb
+except ImportError:
+    import berkeleydb as bsddb
+
 from gi.repository import Gio, GLib, GObject
 
 from xl import shelve_compat
@@ -394,8 +399,8 @@ def open_shelf(path):
     """
     shelve_compat.ensure_shelve_compat()
 
-    # As of Exaile 4, new DBs will only be created as Berkeley DB Hash databases
-    # using either bsddb3 (external) or bsddb (stdlib but sometimes removed).
+    # As of Exaile 4, DBs are created as Berkeley DB Hash databases using
+    # either berkeleydb or bsddb3.
     # Existing DBs created with other backends will be migrated to Berkeley DB.
     # We do this because BDB is generally considered more performant,
     # and because gdbm currently doesn't work at all in MSYS2.
