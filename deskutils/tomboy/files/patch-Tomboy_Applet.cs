--- Tomboy/Applet.cs.orig	Mon Jan 22 14:48:19 2007
+++ Tomboy/Applet.cs	Mon Jan 22 14:48:22 2007
@@ -91,7 +91,9 @@
 
 		void ShowHelpVerb ()
 		{
-			Tomboy.ActionManager ["ShowHelpAction"].Activate ();
+			// Don't use the ActionManager in this case because
+			// the handler won't know about the Screen.
+			GuiUtils.ShowHelp ("tomboy.xml", null, Screen, null);
 		}
 
 		void ShowAboutVerb ()
