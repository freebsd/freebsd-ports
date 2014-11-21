--- virtManager/console.py.orig	2014-11-19 23:37:09 UTC
+++ virtManager/console.py
@@ -20,10 +20,13 @@
 # MA 02110-1301 USA.
 #
 
+import gi
 from gi.repository import GObject
 from gi.repository import Gtk
 from gi.repository import Gdk
+gi.require_version('GtkVnc', '2.0')
 from gi.repository import GtkVnc
+gi.require version('SpiceClientGtk', '3.0')
 from gi.repository import SpiceClientGtk
 from gi.repository import SpiceClientGLib
 
