--- src/export.sml.orig	Fri Mar 30 23:39:11 2001
+++ src/export.sml	Sun Jan 13 13:45:28 2008
@@ -198,6 +198,10 @@
     val moveCItem       : WidId -> CItemId -> Coord -> unit
     val setCItemCoords  : WidId -> CItemId -> Coord list -> unit
 
+(* 4.? List Items *)
+    val addLItemConf : WidId -> Configure list -> Mark -> unit
+    val clearLItemConf : WidId -> Mark -> unit
+
 (* 4.7 Menues *)
     val popUpMenu          : WidId -> int Option.option -> Coord -> unit
 
@@ -433,6 +437,8 @@
         val newWinId             = newWidgetId  (* dodgy *)
 	val newImageId           = newWidgetId  (* me too *)
 
+	val addLItemConf         = WidgetTree.configureLItem
+	val clearLItemConf       = WidgetTree.clearLItemConfig
 
 	(* these also have to check their arguments for non-alphanumerical
 	 * characters etc. *)
@@ -478,8 +484,10 @@
 	fun setFontBasesize x= (#BaseSize(Fonts.Config) := x; initFonts())
 
 	fun xSmlTk{imagefile, banner} 
-	    = SysDep.exportML {init= SysInit.initSmlTk,
-			       banner= banner, imagefile=imagefile}
+	    = (updTclPath (#default SysConf.wishVar);
+               updLibPath (#default SysConf.libVar);
+               SysDep.exportML {init= SysInit.initSmlTk,
+			        banner= banner, imagefile=imagefile})
 
 	val getEnvSetting = SysInit.getEnvSetting
 
