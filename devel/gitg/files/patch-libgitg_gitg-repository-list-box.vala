https://gitlab.gnome.org/GNOME/gitg/issues/213
https://gitlab.gnome.org/GNOME/gitg/merge_requests/83


--- libgitg/gitg-repository-list-box.vala.orig	2019-05-23 11:02:37 UTC
+++ libgitg/gitg-repository-list-box.vala
@@ -407,9 +407,12 @@ namespace Gitg
 			return ((Row)b).time.compare(((Row)a).time);
 		}
 
+		[CCode (cname = "g_bookmark_file_get_uris", array_length_type = "gsize")]
+		extern static string[] bookmark_file_get_uris (BookmarkFile bookmark);
+
 		public void populate_bookmarks()
 		{
-			var uris = d_bookmark_file.get_uris();
+			var uris = bookmark_file_get_uris(d_bookmark_file);
 
 			foreach (var uri in uris)
 			{
