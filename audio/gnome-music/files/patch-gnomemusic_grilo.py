From e357c1fcda9ed1404137f1f941a63c50767250cc Mon Sep 17 00:00:00 2001
From: Sai Suman Prayaga <suman.sai14@gmail.com>
Date: Thu, 22 May 2014 22:27:58 +0530
Subject: Dont update in selection mode

https://bugzilla.gnome.org/show_bug.cgi?id=726713

diff --git a/gnomemusic/grilo.py b/gnomemusic/grilo.py
index efcea25..0de28df 100644
--- gnomemusic/grilo.py
+++ gnomemusic/grilo.py
@@ -68,6 +68,8 @@ class Grilo(GObject.GObject):
         self.tracker = None
         self.changed_media_ids = []
         self.pending_event_id = 0
+        self.changes_pending = {'Albums': False, 'Artists': False, 'Songs': False}
+        self.registry = Grl.Registry.get_default()
 
         self.registry = Grl.Registry.get_default()
         self.registry.connect('source_added', self._on_source_added)
@@ -112,6 +114,9 @@ class Grilo(GObject.GObject):
     def emit_change_signal(self):
         self.changed_media_ids = []
         self.pending_event_id = 0
+        self.changes_pending['Albums'] = True
+        self.changes_pending['Artists'] = True
+        self.changes_pending['Songs'] = True 
         self.emit('changes-pending')
         return False
 
