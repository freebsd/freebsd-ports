--- libvanubi/git.vala.orig	2015-07-03 10:10:29 UTC
+++ libvanubi/git.vala
@@ -27,12 +27,12 @@ namespace Vanubi {
 
 	public class Git {
 		unowned Configuration config;
-		static Regex hunk_regex;
+		static GLib.Regex hunk_regex;
 		static HashTable<DataSource, bool> monitored = new HashTable<DataSource, bool> (DataSource.hash, DataSource.equal);
 		
 		static construct {
 			try {
-				hunk_regex = new Regex ("^@@ -(\\d+),?(\\d*) \\+(\\d+),?(\\d*) @@");
+				hunk_regex = new GLib.Regex ("^@@ -(\\d+),?(\\d*) \\+(\\d+),?(\\d*) @@");
 			} catch (Error e) {
 				warning (e.message);
 			}
