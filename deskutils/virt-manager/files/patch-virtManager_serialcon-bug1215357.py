From 0aeee5c449d608d75f5632e9aa47f5e433eb3879 Mon Sep 17 00:00:00 2001
From: Cole Robinson <crobinso@redhat.com>
Date: Sun, 26 Apr 2015 11:50:01 -0400
Subject: serialcon: Fix opening with xen (bz 1215357)

Apparently xen doesn't set <serial> device alias names, and OpenConsole
just opens the first <console> device unconditionally.

Properly handling that would be to report it in the UI that we can
only open the first console, but for now just drop the alias check.
Apparently SUSE already does this as mentioned in the RH bug

https://bugzilla.redhat.com/show_bug.cgi?id=1215357

diff --git a/virtManager/serialcon.py b/virtManager/serialcon.py
index 92c2029..320811b 100644
--- ./virtManager/serialcon.py
+++ ./virtManager/serialcon.py
@@ -205,8 +205,9 @@ class LibvirtConsoleConnection(ConsoleConnection):
         name = dev and dev.alias.name or None
         logging.debug("Opening console stream for dev=%s alias=%s",
                       dev, name)
-        if not name:
-            raise RuntimeError(_("Cannot open a device with no alias name"))
+        # libxl doesn't set aliases, their open_console just defaults to
+        # opening the first console device, so don't force prescence of
+        # an alias
 
         stream = self.conn.get_backend().newStream(libvirt.VIR_STREAM_NONBLOCK)
         self.vm.open_console(name, stream)
-- 
cgit v0.10.2
