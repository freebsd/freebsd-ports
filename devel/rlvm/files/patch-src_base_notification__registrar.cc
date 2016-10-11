https://github.com/eglaysher/rlvm/issues/80

--- src/base/notification_registrar.cc.orig	2016-07-30 22:27:57 UTC
+++ src/base/notification_registrar.cc
@@ -46,7 +46,12 @@ void NotificationRegistrar::Remove(Notif
   }
 
   Record record = { observer, type, source };
+#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ < 5
+  RecordVector::iterator found = std::find(
+      registered_.begin(), registered_.end(), record);
+#else
   auto found = std::find(registered_.cbegin(), registered_.cend(), record);
+#endif
   registered_.erase(found);
 
   // This can be NULL if our owner outlives the NotificationService, e.g. if our
