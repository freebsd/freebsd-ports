https://gitlab.gnome.org/GNOME/gitg/issues/213
https://gitlab.gnome.org/GNOME/gitg/merge_requests/83

--- libgitg/gitg-diff-view.vala.orig	2019-05-23 11:02:37 UTC
+++ libgitg/gitg-diff-view.vala
@@ -131,8 +131,11 @@ public class Gitg.DiffView : Gtk.Grid
 		get { return d_repository; }
 		set {
 			d_repository = value;
-			config_file = "%s/.git/config".printf(d_repository.get_workdir().get_path());
-			d_commit_details.config_file = config_file;
+			if (d_repository!=null)
+			{
+				config_file = "%s/.git/config".printf(d_repository.get_workdir().get_path());
+				d_commit_details.config_file = config_file;
+			}
 		}
 	}
 	public bool new_is_workdir { get; set; }
@@ -593,34 +596,37 @@ public class Gitg.DiffView : Gtk.Grid
 
 	private void read_ini_file(Gtk.TextBuffer buffer)
 	{
-		GLib.KeyFile file = new GLib.KeyFile();
-
-		try
+		if (config_file != null)
 		{
-			if (file.load_from_file(config_file , GLib.KeyFileFlags.NONE))
+			try
 			{
-				foreach (string group in file.get_groups())
+				GLib.KeyFile file = new GLib.KeyFile();
+				if (file.load_from_file(config_file , GLib.KeyFileFlags.NONE))
 				{
-					if (group.has_prefix("gitg.custom-link"))
+					foreach (string group in file.get_groups())
 					{
-						string custom_link_regexp = file.get_string (group, "regexp");
-						string custom_link_replacement = file.get_string (group, "replacement");
-						bool custom_color = file.has_key (group, "color");
-						Gdk.RGBA color = d_color_link;
-						if (custom_color)
+						if (group.has_prefix("gitg.custom-link"))
 						{
-							string custom_link_color = file.get_string (group, "color");
-							color = Gdk.RGBA();
-							color.parse(custom_link_color);
+							string custom_link_regexp = file.get_string (group, "regexp");
+							string custom_link_replacement = file.get_string (group, "replacement");
+							bool custom_color = file.has_key (group, "color");
+							Gdk.RGBA color = d_color_link;
+							if (custom_color)
+							{
+								string custom_link_color = file.get_string (group, "color");
+								color = Gdk.RGBA();
+								color.parse(custom_link_color);
+							}
+							apply_link_tags(buffer, new Regex (custom_link_regexp), custom_link_replacement, color, custom_color, true);
 						}
-						apply_link_tags(buffer, new Regex (custom_link_regexp), custom_link_replacement, color, custom_color, true);
 					}
 				}
+			} catch (Error e)
+			{
+				warning ("Cannot read %s: %s", config_file, e.message);
 			}
-		} catch (Error e)
-		{
-			warning ("Cannot read %s: %s", config_file, e.message);
 		}
+
 	}
 
 	private void auto_change_expanded(bool expanded)
