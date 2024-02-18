--- src/documents/management/commands/document_consumer.py.orig	2024-02-19 16:25:10 UTC
+++ src/documents/management/commands/document_consumer.py
@@ -292,7 +292,7 @@ class Command(BaseCommand):
             logger.debug(f"Configuring timeout to {timeout}ms")
 
         inotify = INotify()
-        inotify_flags = flags.CLOSE_WRITE | flags.MOVED_TO | flags.MODIFY
+        inotify_flags = flags.CLOSE_WRITE | flags.MOVED_TO | flags.MODIFY | flags.CREATE
         if recursive:
             descriptor = inotify.add_watch_recursive(directory, inotify_flags)
         else:
@@ -342,7 +342,7 @@ class Command(BaseCommand):
                 # If files are waiting, need to exit read() to check them
                 # Otherwise, go back to infinite sleep time, but only if not testing
                 if len(notified_files) > 0:
-                    timeout = inotify_debounce
+                    timeout = inotify_debounce * 1000
                 elif is_testing:
                     timeout = self.testing_timeout_ms
                 else:
