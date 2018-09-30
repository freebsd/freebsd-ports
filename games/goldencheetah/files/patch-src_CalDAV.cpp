From a771b9629aab39de1ab1edd0e8b5180af2ab53a0 Mon Sep 17 00:00:00 2001
From: Mark Liversedge <liversedge@gmail.com>
Date: Sun, 29 Oct 2017 15:03:44 +0000
Subject: [PATCH] libical 2 compatibility

.. isUTC no longer present (and was never needed anyway).
---
 src/Cloud/CalDAV.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

--- src/CalDAV.cpp.orig	2015-08-12 08:43:33 UTC
+++ src/CalDAV.cpp
@@ -274,7 +274,7 @@ icalcomponent *createEvent(RideItem *rideItem)
     atime.hour = utc.time().hour();
     atime.minute = utc.time().minute();
     atime.second = utc.time().second();
-    atime.is_utc = 1; // this is UTC is_utc is redundant but kept for completeness
+    //atime.is_utc = 1; // this is UTC is_utc is redundant but kept for completeness
     atime.is_date = 0; // this is a date AND time
     atime.is_daylight = 0; // no daylight savings - its UTC
     atime.zone = icaltimezone_get_utc_timezone(); // set UTC timezone
