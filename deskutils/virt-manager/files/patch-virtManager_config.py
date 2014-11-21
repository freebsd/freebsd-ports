--- virtManager/config.py.orig	2014-11-19 23:35:48 UTC
+++ virtManager/config.py
@@ -20,8 +20,10 @@
 import os
 import logging
 
+import gi
 from gi.repository import Gio
 from gi.repository import GLib
+gi.require_version('Gtk', '3.0')
 from gi.repository import Gtk
 
 from virtinst import CPU
