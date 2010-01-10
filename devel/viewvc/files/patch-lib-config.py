--- lib/config.py.orig	2010-01-07 10:44:45.000000000 -0800
+++ lib/config.py	2010-01-07 10:44:50.000000000 -0800
@@ -274,9 +274,7 @@
     """Overlay per-root options for ROOTNAME atop the existing option
     set.  This is a destructive change to the configuration."""
 
-    # We can only deal with this happening once!
-    assert(self.root_options_overlayed == 0)
-    self.root_options_overlayed = 1
+    did_overlay = 0
     
     if not self.conf_path:
       return
@@ -285,7 +283,17 @@
       base_section = self._is_allowed_override(self.parser, 'root',
                                                rootname, section)
       if base_section:
+        # We can currently only deal with root overlays happening
+        # once, so check that we've not yet done any overlaying of
+        # per-root options.
+        assert(self.root_options_overlayed == 0)
         self._process_section(self.parser, section, base_section)
+        did_overlay = 1
+
+    # If we actually did any overlaying, remember this fact so we
+    # don't do it again later.
+    if did_overlay:
+      self.root_options_overlayed = 1
 
   def _get_parser_items(self, parser, section):
     """Basically implement ConfigParser.items() for pre-Python-2.3 versions."""
