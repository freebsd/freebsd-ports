--- src/documents/management/commands/document_consumer.py.orig	2024-03-18 03:45:09 UTC
+++ src/documents/management/commands/document_consumer.py
@@ -292,7 +292,7 @@ class Command(BaseCommand):
             logger.debug(f"Configuring timeout to {timeout_ms}ms")
 
         inotify = INotify()
-        inotify_flags = flags.CLOSE_WRITE | flags.MOVED_TO | flags.MODIFY
+        inotify_flags = flags.CLOSE_WRITE | flags.MOVED_TO | flags.MODIFY | flags.CREATE
         if recursive:
             descriptor = inotify.add_watch_recursive(directory, inotify_flags)
         else:
