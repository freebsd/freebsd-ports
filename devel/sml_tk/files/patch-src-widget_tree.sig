--- ./src/widget_tree.sig.orig	Fri Mar 30 23:39:23 2001
+++ src/widget_tree.sig	Sun Jan 13 11:10:20 2008
@@ -196,6 +196,10 @@
 	                       BasicTypes.Mark * BasicTypes.Mark -> unit
 	val clearText        : BasicTypes.WidId -> unit
 
+	val configureLItem   : BasicTypes.WidId -> TkTypes.Configure list ->
+	                       BasicTypes.Mark -> unit
+	val clearLItemConfig : BasicTypes.WidId -> BasicTypes.Mark -> unit
+
 
 	val focus   : BasicTypes.WinId -> unit
 	val deFocus : BasicTypes.WinId -> unit
