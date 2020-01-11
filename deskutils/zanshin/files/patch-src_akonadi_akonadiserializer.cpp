Description: KCalendarCore 19.08 API changes.
  There is no KCalCore::Attendee::Ptr anymore instead the API returns
  KCalCore::Attendee items. Like done in 
  upstream_Make-it-build-both-with-pre-and-post-19.08.0-KCalCor.patch
  make it possible to build with a wide range of KCalCore versions.
  This is not needed to get upstream as master has removed this part of code.
Author: Hefee <hefee@debian.org>
Origin: debian
Forwarded: not-needed
Last-Update: 2014-02-17
---
This patch header follows DEP-3: http://dep.debian.net/deps/dep3/
--- src/akonadi/akonadiserializer.cpp
+++ src/akonadi/akonadiserializer.cpp
@@ -272,6 +272,15 @@ void Serializer::updateTaskFromItem(Doma
 
     if (todo->attendeeCount() > 0) {
         const auto attendees = todo->attendees();
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 90)
+        const auto delegate = std::find_if(attendees.begin(), attendees.end(),
+                                           [] (const KCalCore::Attendee &attendee) {
+                                               return attendee.status() == KCalCore::Attendee::Accepted;
+                                           });
+        if (delegate != attendees.end()) {
+            task->setDelegate(Domain::Task::Delegate((*delegate).name(), (*delegate).email()));
+        }
+#else
         const auto delegate = std::find_if(attendees.begin(), attendees.end(),
                                            [] (const KCalCore::Attendee::Ptr &attendee) {
                                                return attendee->status() == KCalCore::Attendee::Accepted;
@@ -279,6 +288,7 @@ void Serializer::updateTaskFromItem(Doma
         if (delegate != attendees.end()) {
             task->setDelegate(Domain::Task::Delegate((*delegate)->name(), (*delegate)->email()));
         }
+#endif
     }
 }
 
@@ -363,10 +373,17 @@ Akonadi::Item Serializer::createItemFrom
     }
 
     if (task->delegate().isValid()) {
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 90)
+        KCalCore::Attendee attendee(task->delegate().name(),
+                                    task->delegate().email(),
+                                    true,
+                                    KCalCore::Attendee::Accepted);
+#else
         KCalCore::Attendee::Ptr attendee(new KCalCore::Attendee(task->delegate().name(),
                                                                 task->delegate().email(),
                                                                 true,
                                                                 KCalCore::Attendee::Accepted));
+#endif
         todo->addAttendee(attendee);
     }
     if (task->isRunning()) {
