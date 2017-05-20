From 4b61966a93e7be65ed35e8a509e2b7538b136c3c Mon Sep 17 00:00:00 2001
From: Adam Dingle <adam@medovina.org>
Date: Thu, 24 Mar 2016 12:35:04 -0400
Subject: Fix build with newer evolution-data-server: bug 743961

Thanks to Milan Crha <mcrha@redhat.com> for this fix.

https://bugzilla.gnome.org/show_bug.cgi?id=743961
---
 configure.ac                                     | 2 +-
 src/backing/eds/backing-eds-calendar-source.vala | 2 +-
 vapi/libecal-1.2.vapi                            | 2 +-
 3 files changed, 3 insertions(+), 3 deletions(-)

diff --git a/src/backing/eds/backing-eds-calendar-source.vala b/src/backing/eds/backing-eds-calendar-source.vala
index 7e30e08..da88db4 100644
--- src/backing/eds/backing-eds-calendar-source.vala
+++ src/backing/eds/backing-eds-calendar-source.vala
@@ -256,7 +256,7 @@ internal class EdsCalendarSource : CalendarSource {
     
     // Invoked by EdsStore prior to making it available outside of unit
     internal async void open_async(Cancellable? cancellable) throws Error {
-        client = (E.CalClient) yield E.CalClient.connect(eds_source, E.CalClientSourceType.EVENTS,
+        client = (E.CalClient) yield E.CalClient.connect(eds_source, E.CalClientSourceType.EVENTS, 1,
             cancellable);
         
         client.bind_property("readonly", this, PROP_READONLY, BindingFlags.SYNC_CREATE);
diff --git a/vapi/libecal-1.2.vapi b/vapi/libecal-1.2.vapi
index 6ead3ec..46fd711 100644
--- vapi/libecal-1.2.vapi
+++ vapi/libecal-1.2.vapi
@@ -23,7 +23,7 @@ namespace E {
 		public bool check_save_schedules ();
 		public static bool check_timezones (iCal.icalcomponent comp, GLib.List comps, GLib.Callback tzlookup, void* ecalclient, GLib.Cancellable cancellable) throws GLib.Error;
 		[CCode (finish_name = "e_cal_client_connect_finish")]
-		public static async unowned E.Client connect (E.Source source, E.CalClientSourceType source_type, GLib.Cancellable cancellable) throws GLib.Error;
+		public static async unowned E.Client connect (E.Source source, E.CalClientSourceType source_type, uint32 wait_for_connected_seconds, GLib.Cancellable cancellable) throws GLib.Error;
 		public static unowned E.Client connect_sync (E.Source source, E.CalClientSourceType source_type, GLib.Cancellable cancellable) throws GLib.Error;
 		[CCode (finish_name = "e_cal_client_create_object_finish")]
 		public async void create_object (iCal.icalcomponent icalcomp, GLib.Cancellable? cancellable, out string out_uid) throws GLib.Error;
-- 
cgit v0.12

