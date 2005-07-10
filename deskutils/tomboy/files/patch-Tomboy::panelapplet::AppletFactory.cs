===================================================================
RCS file: /cvs/gnome/tomboy/Tomboy/panelapplet/AppletFactory.cs,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- Tomboy/panelapplet/AppletFactory.cs	2004/10/23 18:21:58	1.1
+++ Tomboy/panelapplet/AppletFactory.cs	2005/06/08 10:31:47	1.2
@@ -4,9 +4,9 @@
 
 namespace PanelApplet
 {
-	public class AppletFactory
+	public class AppletFactory : GLib.Object
 	{
-		private AppletFactory () { }
+		private AppletFactory () : base (IntPtr.Zero) { }
 
 		private static string _IID;
 		private static string _factoryIID;
