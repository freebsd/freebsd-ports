# gitg crash on exit if built with -fstack-protector-all
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234607
# https://gitlab.gnome.org/GNOME/gitg/issues/171
--- libgitg/gitg-repository-list-box.vala
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
