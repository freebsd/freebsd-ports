https://github.com/notify-rs/notify/commit/41a74f0e98a1af386749ad3be4a197865054f17f

--- cargo-crates/notify-5.0.0-pre.14/src/kqueue.rs.orig	2022-04-22 10:42:02 UTC
+++ cargo-crates/notify-5.0.0-pre.14/src/kqueue.rs
@@ -263,6 +263,10 @@ impl EventLoop {
                             remove_watches.push(path.clone());
                             Ok(Event::new(EventKind::Remove(RemoveKind::Any)).add_path(path))
                         }
+
+                        // On different BSD variants, different extra events may be present
+                        #[allow(unreachable_patterns)]
+                        _ => Ok(Event::new(EventKind::Other)),
                     };
                     self.event_handler.handle_event(event);
                 }
