Support for x11/ptyxis and x11/gnome-console (kgx)

--- src/file_item.vala.orig	2023-10-16 12:20:36 UTC
+++ src/file_item.vala
@@ -227,6 +227,8 @@ public class FileItem : DesktopItem {
 			// alacritty supports -e, --working-directory WITHOUT equal
 			// gnome-terminal supports --tab and --working-directory (no -w) WITH equal, but not -e
 			// mate-terminal supports --tab and -e, --working-directory (no -w) WITH equal
+			// kgx (gnome-console) supports --tab and -e, --working-directory (no -w) WITH equal
+			// ptyxis supports --tab and -x, --working-directory (no -w) WITH equal
 			// konsole supports --new-tab and -e, --workdir WITHOUT equal
 			// kitty supports --directory WITH equal
 			// terminator supports --new-tab and -e,  --working-directory (no -w) WITH equal
@@ -235,10 +237,11 @@ public class FileItem : DesktopItem {
 				(preferred_terminal != "alacritty") && // Not Alacritty, no tab CLI flag
 				(preferred_terminal != "gnome-terminal") && // Not GNOME Terminal which uses --tab instead of --new-tab
 				(preferred_terminal != "tilix") && // No new tab CLI flag (that I saw anyways)
-				(preferred_terminal != "kitty") // No new tab CLI flag for Kitty, either
+				(preferred_terminal != "kitty") && // No new tab CLI flag for Kitty, either
+				(preferred_terminal != "kgx") && (preferred_terminal != "ptyxis")
 			) {
 				args += "--new-tab"; // Add --new-tab
-			} else if ((preferred_terminal == "gnome-terminal") && (_type == "file")) { // GNOME Terminal, self explanatory really
+			} else if ((preferred_terminal == "gnome-terminal" || preferred_terminal == "kgx" || preferred_terminal == "ptyxis") && (_type == "file")) { // GNOME Terminal, self explanatory really
 				args += "--tab"; // Create a new tab in an existing window or creates a new window
 			}
 
@@ -269,6 +272,10 @@ public class FileItem : DesktopItem {
 
 				if (preferred_terminal == "gnome-terminal") { // gnome-terminal will not work with -e
 					args += "--";
+					args += editor;
+					args += path;
+				} else if (preferred_terminal == "ptyxis") {
+					args += "-x";
 					args += editor;
 					args += path;
 				} else {
