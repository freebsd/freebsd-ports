From 2d484fda1b31a72659088a4bfce5c3708e923cb0 Mon Sep 17 00:00:00 2001
From: David Faure <faure@kde.org>
Date: Tue, 23 Jul 2019 12:20:29 +0200
Subject: Fix compilation after recent KCalCore API changes


diff --git a/src/plugins/filters/icalendar/export/icalendarexport.cpp b/src/plugins/filters/icalendar/export/icalendarexport.cpp
index 757d693..5eba36b 100644
--- src/plugins/filters/icalendar/export/icalendarexport.cpp
+++ src/plugins/filters/icalendar/export/icalendarexport.cpp
@@ -31,6 +31,7 @@
 #include <kcalcore/attachment.h>
 #include <kcalcore/icalformat.h>
 #include <kcalcore/memorycalendar.h>
+#define KCALCORE_VERSION QT_VERSION_CHECK(5,61,0)
 
 #include <QTextCodec>
 #include <QByteArray>
@@ -140,9 +141,15 @@ void ICalendarExport::createTodos(KCalCore::Calendar::Ptr cal, const Node *node,
         todo->setOrganizer(node->projectNode()->leader());
     }
     if ( node->type() != Node::Type_Project && ! node->leader().isEmpty()) {
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 80)
+        KCalCore::Person p = KCalCore::Person::fromFullName(node->leader());
+        KCalCore::Attendee a(p.name(), p.email());
+        a.setRole(KCalCore::Attendee::NonParticipant);
+#else
         KCalCore::Person::Ptr p = KCalCore::Person::fromFullName(node->leader());
         KCalCore::Attendee::Ptr a(new KCalCore::Attendee(p->name(), p->email()));
         a->setRole(KCalCore::Attendee::NonParticipant);
+#endif
         todo->addAttendee(a);
     }
     DateTime st = node->startTime(id);
@@ -161,13 +168,21 @@ void ICalendarExport::createTodos(KCalCore::Calendar::Ptr cal, const Node *node,
             const QList<Resource*> lst = task->requestedResources();
             foreach(const Resource *r, lst) {
                 if (r->type() == Resource::Type_Work) {
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 80)
+                    todo->addAttendee(KCalCore::Attendee(r->name(), r->email()));
+#else
                     todo->addAttendee(KCalCore::Attendee::Ptr(new KCalCore::Attendee(r->name(), r->email())));
+#endif
                 }
             }
         } else {
             foreach(const Resource *r, s->resources()) {
                 if (r->type() == Resource::Type_Work) {
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 80)
+                    todo->addAttendee(KCalCore::Attendee(r->name(), r->email()));
+#else
                     todo->addAttendee(KCalCore::Attendee::Ptr(new KCalCore::Attendee(r->name(), r->email())));
+#endif
                 }
             }
 
@@ -178,7 +193,11 @@ void ICalendarExport::createTodos(KCalCore::Calendar::Ptr cal, const Node *node,
         todo->setPercentComplete(task->completion().percentFinished());
     }
     foreach(const Document *doc, node->documents().documents()) {
+#if KCALCORE_VERSION >= QT_VERSION_CHECK(5, 11, 80)
+        todo->addAttachment(KCalCore::Attachment(doc->url().url()));
+#else
         todo->addAttachment(KCalCore::Attachment::Ptr(new KCalCore::Attachment(doc->url().url())));
+#endif
     }
     if (! parent.isNull()) {
         todo->setRelatedTo(parent->uid(), KCalCore::Incidence::RelTypeParent);
