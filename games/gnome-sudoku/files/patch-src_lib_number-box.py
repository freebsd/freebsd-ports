--- src/lib/number_box.py.orig	2013-08-24 20:08:03.000000000 +0200
+++ src/lib/number_box.py	2013-08-24 20:08:32.000000000 +0200
@@ -130,7 +130,7 @@
         self.bottom_note_list = []
         self.tinfo = tracker_info.TrackerInfo()
         self.set_property('can-focus', True)
-        self.set_property('events', Gdk.EventMask.ALL_EVENTS_MASK)
+        self.add_events(Gdk.EventMask.ALL_EVENTS_MASK)
         self.connect('button-press-event', self.button_press_cb)
         self.connect('key-release-event', self.key_press_cb)
         self.connect('enter-notify-event', self.pointer_enter_cb)
