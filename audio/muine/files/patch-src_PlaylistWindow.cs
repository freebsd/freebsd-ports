--- src/PlaylistWindow.cs.orig	Sun May  1 12:25:15 2005
+++ src/PlaylistWindow.cs	Fri Sep  9 20:12:56 2005
@@ -431,7 +431,7 @@
 		public void RestorePlaylist ()
 		{
 			// Load last playlist
-			if (!File.Exists (FileUtils.PlaylistFile))
+			if (!System.IO.File.Exists (FileUtils.PlaylistFile))
 				return;
 
 			OpenPlaylistInternal (FileUtils.PlaylistFile,
