Merge the IN_ATTRIB + IN_MODIFY pair that FreeBSD's inotify reports for
a truncation into one modify event, as Linux reports it (series 0019).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/file_system_watcher_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/file_system_watcher_linux.cc
@@ -123,6 +123,21 @@ Dart_Handle FileSystemWatcher::ReadEvents(intptr_t id,
     if ((e->mask & IN_IGNORED) == 0) {
       Dart_Handle event = Dart_NewList(kEventNumElements);
       int mask = InotifyEventToMask(e);
+#if defined(__FreeBSD__)
+      // Where Linux reports a single IN_MODIFY (e.g. for a truncate), FreeBSD
+      // reports IN_ATTRIB followed by IN_MODIFY. Report them as one event.
+      const intptr_t next_offset = offset + kEventSize + e->len;
+      if ((e->mask & IN_ATTRIB) != 0 && next_offset < bytes) {
+        struct inotify_event* next =
+            reinterpret_cast<struct inotify_event*>(buffer + next_offset);
+        if ((next->mask & IN_MODIFY) != 0 && next->wd == e->wd &&
+            next->len == e->len &&
+            (e->len == 0 || strcmp(next->name, e->name) == 0)) {
+          mask |= InotifyEventToMask(next);
+          offset = next_offset;
+        }
+      }
+#endif
       Dart_ListSetAt(event, kEventFlagsIndex, Dart_NewInteger(mask));
       Dart_ListSetAt(event, kEventCookieIndex, Dart_NewInteger(e->cookie));
       if (e->len > 0) {
