--- src/widget_tree.sml.orig	Sun Jan 13 12:42:32 2008
+++ src/widget_tree.sml	Sun Jan 13 12:44:14 2008
@@ -1171,9 +1171,9 @@
 		if (List.exists (Config.confEq fdef) nc) then nc else fdef::nc
 	in
 	    (packWid doP "frame" tp ip wid p [] [] grid ^
+	     packWid true "scrollbar" sctp scip wid [si,Fill Y] [] [] false ^
 	     packWid true "text" btp bip wid [siquer,Fill Both,Expand true] nc'
 	             b false ^
-	     packWid true "scrollbar" sctp scip wid [si,Fill Y] [] [] false ^
 	     btp ^ " configure -yscrollcommand \"" ^ sctp ^ " set \" " ^ "\n" ^
 	     sctp^" configure -command \""^ btp ^ " yview\"" ^ "\n" ^
 	     tt ^ stt ^
@@ -1547,6 +1547,49 @@
    end
 
 fun clearText wid = deleteText wid (Mark(0, 0), MarkEnd)
+
+fun configureLItem wid cf m =
+    let
+	fun litempack [] = ""
+	  | litempack ((Foreground c)::xs) = let
+		val coltext = Config.showColor c
+	      in
+		" -foreground " ^ coltext ^
+		" -selectforeground " ^ coltext ^ litempack xs
+	      end
+	  | litempack ((Background c)::xs) =
+	      " -background " ^ (Config.showColor c) ^ litempack xs
+	  | litempack (_::xs) = litempack xs
+	val ip = Paths.getIntPathGUI wid
+	val tp = Paths.getTclPathGUI ip
+	val w = getWidgetGUIPath ip
+	val (m1, _)= StringUtil.breakAtDot (Mark.show m)
+    in
+	case w of
+	    Listbox _ =>
+		Com.putTclCmd (tp ^ ".box itemconfigure " ^ m1 ^ " " ^
+			       litempack cf)
+	  | _         =>
+		raise WIDGET "text insertion in illegal window"
+    end
+
+fun clearLItemConfig wid m =
+    let
+	val ip = Paths.getIntPathGUI wid
+	val tp = Paths.getTclPathGUI ip
+	val tp = Paths.getTclPathGUI (Paths.getIntPathGUI wid)
+	val w = getWidgetGUIPath ip
+	val (m1,_)= StringUtil.breakAtDot (Mark.show m)
+    in
+	case w of
+	    Listbox _ =>
+		Com.putTclCmd (tp ^ ".box itemconfigure " ^ m1 ^
+			       " -foreground \"\" -selectforeground \"\" " ^
+			       " -background \"\" -selectbackground \"\"")
+	  | _         =>
+		raise WIDGET "text insertion in illegal window"
+    end
+
 
 fun focus win =
     if ( win = "main" orelse win = "." ) then
