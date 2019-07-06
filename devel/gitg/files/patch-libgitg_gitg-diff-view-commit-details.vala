https://gitlab.gnome.org/GNOME/gitg/issues/213
https://gitlab.gnome.org/GNOME/gitg/merge_requests/83

--- libgitg/gitg-diff-view-commit-details.vala.orig	2019-05-23 11:02:37 UTC
+++ libgitg/gitg-diff-view-commit-details.vala
@@ -281,65 +281,69 @@ class Gitg.DiffViewCommitDetails : Gtk.Grid
 
 	private string parse_ini_file(string subject_text)
 	{
-		string result = subject_text.dup();
-		GLib.KeyFile file = new GLib.KeyFile();
-
-		try
+		string result = subject_text;
+		if (config_file!=null)
 		{
-			debug ("parsing %s", config_file);
-			if (file.load_from_file(config_file , GLib.KeyFileFlags.NONE))
+			try
 			{
-				foreach (string group in file.get_groups())
+				debug ("parsing %s", config_file);
+				GLib.KeyFile file = new GLib.KeyFile();
+				if (file.load_from_file(config_file , GLib.KeyFileFlags.NONE))
 				{
-					if (group.has_prefix("gitg.custom-link"))
+					result = subject_text.dup();
+					foreach (string group in file.get_groups())
 					{
-						string custom_link_regexp = file.get_string (group, "regexp");
-						string custom_link_replacement = file.get_string (group, "replacement");
-						debug ("found group: %s", custom_link_regexp);
-						bool custom_color = file.has_key (group, "color");
-						string color = null;
-						if (custom_color)
+						if (group.has_prefix("gitg.custom-link"))
 						{
-							string custom_link_color = file.get_string (group, "color");
-							color = custom_link_color;
-						}
+							string custom_link_regexp = file.get_string (group, "regexp");
+							string custom_link_replacement = file.get_string (group, "replacement");
+							debug ("found group: %s", custom_link_regexp);
+							bool custom_color = file.has_key (group, "color");
+							string color = null;
+							if (custom_color)
+							{
+								string custom_link_color = file.get_string (group, "color");
+								color = custom_link_color;
+							}
 
-						var custom_regex = new Regex (custom_link_regexp);
-						try
-						{
-							GLib.MatchInfo matchInfo;
+							var custom_regex = new Regex (custom_link_regexp);
+							try
+							{
+								GLib.MatchInfo matchInfo;
 
-							custom_regex.match (subject_text, 0, out matchInfo);
+								custom_regex.match (subject_text, 0, out matchInfo);
 
-							while (matchInfo.matches ())
-							{
-								string text = matchInfo.fetch(0);
-								string link = text.dup();
-								debug ("found: %s", link);
-								if (custom_link_replacement != null)
+								while (matchInfo.matches ())
 								{
-									link = custom_regex.replace(link, text.length, 0, custom_link_replacement);
-								}
-								if (color != null) {
-									result = result.replace(text, "<a href=\"%s\" title=\"%s\" style=\"color:%s\">%s</a>".printf(link, link, color, text));
-								} else {
-									result = result.replace(text, "<a href=\"%s\" title=\"%s\">%s</a>".printf(link, link, text));
-								}
+									string text = matchInfo.fetch(0);
+									string link = text.dup();
+									debug ("found: %s", link);
+									if (custom_link_replacement != null)
+									{
+										link = custom_regex.replace(link, text.length, 0, custom_link_replacement);
+									}
+									if (color != null) {
+										result = result.replace(text, "<a href=\"%s\" title=\"%s\" style=\"color:%s\">%s</a>".printf(link, link, color, text));
+									} else {
+										result = result.replace(text, "<a href=\"%s\" title=\"%s\">%s</a>".printf(link, link, text));
+									}
 
-								matchInfo.next();
+									matchInfo.next();
+								}
 							}
+							catch(Error e)
+							{
+							}
 						}
-						catch(Error e)
-						{
-						}
 					}
 				}
+			} catch (Error e)
+			{
+				warning ("Cannot read %s %s", config_file, e.message);
 			}
-		} catch (Error e)
-		{
-			warning ("Cannot read %s %s", config_file, e.message);
 		}
 		return result;
+
 	}
 
 	private void update_avatar()
