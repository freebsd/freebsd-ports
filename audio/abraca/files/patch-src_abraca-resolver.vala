--- src/abraca-resolver.vala.orig	2014-10-26 18:55:55 UTC
+++ src/abraca-resolver.vala
@@ -63,8 +63,8 @@ public class Abraca.MetadataResolver : GLib.Object {
 
 	private Gee.List<MetadataRequestorImpl> listeners = new Gee.ArrayList<MetadataRequestorImpl>();
 
-	private Gee.List<int> pending = new Gee.ArrayList<uint>();
-	private Gee.Map<int,Xmms.Collection> pending_mids = new Gee.HashMap<uint,Xmms.Collection>();
+	private Gee.List<int> pending = new Gee.ArrayList<int>();
+	private Gee.Map<int,Xmms.Collection> pending_mids = new Gee.HashMap<int,Xmms.Collection>();
 
 	private uint timeout_handle = 0;
 	private bool in_flight = false;
