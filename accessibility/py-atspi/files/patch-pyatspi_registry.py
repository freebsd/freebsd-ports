Upstream patch for https://gitlab.gnome.org/GNOME/pyatspi2/issues/1

diff --git pyatspi/registry.py pyatspi/registry.py
index cb28395..f73ee16 100644
--- pyatspi/registry.py
+++ pyatspi/registry.py
@@ -50,9 +50,9 @@ class Registry(object):
         reference to the Accessibility.Registry singleton. Doing so is harmless and
         has no point.
 
-        @@ivar async: Should event dispatch to local listeners be decoupled from event
-                receiving from the registry?
-        @@type async: boolean
+        @@ivar asynchronous: Should event dispatch to local listeners be decoupled
+                from event receiving from the registry?
+        @@type asynchronous: boolean
         @@ivar reg: Reference to the real, wrapped registry object
         @@type reg: Accessibility.Registry
         @@ivar dev: Reference to the device controller
@@ -111,25 +111,44 @@ def _set_registry (self, main_loop_type, app_name=None):
 
                 self.has_implementations = True
 
-                self.async = False	# not fully supported yet
+                self.asynchronous = False	# not fully supported yet
                 self.started = False
                 self.event_listeners = dict()
 
+        def __getattr__(self, name):
+            """
+            For backwards compatibility with old API
+            """
+            if name == 'async':
+                return self.asynchronous
+            return object.__getattr__(self, name)
+
+        def __setattr__(self, name, value):
+            """
+            For backwards compatibility with old API
+            """
+            if name == 'async':
+                self.asynchronous = value
+            object.__setattr__(self, name, value)
+
         def _set_default_registry (self):
                 self._set_registry (MAIN_LOOP_GLIB)
 
-        def start(self, async=False, gil=True):
+        def start(self, asynchronous=False, gil=True, **kwargs):
                 """
                 Enter the main loop to start receiving and dispatching events.
 
-                @@param async: Should event dispatch be asynchronous (decoupled) from 
-                        event receiving from the AT-SPI registry?
-                @@type async: boolean
+                @@param asynchronous: Should event dispatch be asynchronous
+                        (decoupled) from event receiving from the AT-SPI registry?
+                @@type asynchronous: boolean
                 @@param gil: Add an idle callback which releases the Python GIL for a few
                         milliseconds to allow other threads to run? Necessary if other threads
                         will be used in this process.
                 @@type gil: boolean
                 """
+                if 'async' in kwargs:
+                    # support previous API
+                    asynchronous = kwargs['async']
                 if not self.has_implementations:
                         self._set_default_registry ()
                 self.started = True
