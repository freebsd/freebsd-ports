--- ./src/config.sml.orig	Fri Mar 30 23:39:07 2001
+++ src/config.sml	Sun Jan 13 11:10:08 2008
@@ -339,22 +339,22 @@
 local
     fun round n =
 	if n < 0 then 0 else if n > 255 then 255 else n
+    val toStr =
+	(StringCvt.padLeft #"0" 2) o Word.toString o Word.fromInt o round
 in
-    fun showCol NoColor= "{}"
-      | showCol Black  = "black"
-      | showCol White  = "white"
-      | showCol Grey   = "grey"
-      | showCol Blue   = "blue"
-      | showCol Green  = "green"
-      | showCol Red    = "red"
-      | showCol Brown  = "brown"
-      | showCol Yellow = "yellow"
-      | showCol Purple = "purple"
-      | showCol Orange = "orange"
-      | showCol (Mix {red, blue, green}) =
-	"\"#"^Word.toString(Word.fromInt(round red)) ^
-	Word.toString(Word.fromInt(round green)) ^
-	Word.toString(Word.fromInt(round blue)) ^ "\""
+    fun showColor NoColor= "{}"
+      | showColor Black  = "black"
+      | showColor White  = "white"
+      | showColor Grey   = "grey"
+      | showColor Blue   = "blue"
+      | showColor Green  = "green"
+      | showColor Red    = "red"
+      | showColor Brown  = "brown"
+      | showColor Yellow = "yellow"
+      | showColor Purple = "purple"
+      | showColor Orange = "orange"
+      | showColor (Mix {red, blue, green}) =
+	"\"#"^ toStr red ^ toStr green ^ toStr blue ^ "\""
 end
 
 fun showAnchorKind North     = "n"
@@ -384,13 +384,13 @@
 
 fun showCursorKind (NoCursor)                      = "{}"
   | showCursorKind (XCursor(cn,NONE))              = cn
-  | showCursorKind (XCursor(cn,SOME(fg,NONE)))     = cn ^ " " ^ (showCol fg)
+  | showCursorKind (XCursor(cn,SOME(fg,NONE)))     = cn ^ " " ^ (showColor fg)
   | showCursorKind (XCursor(cn,SOME(fg,SOME(bg)))) =
-    cn ^ " " ^ (showCol fg)^ " " ^ (showCol bg)
+    cn ^ " " ^ (showColor fg)^ " " ^ (showColor bg)
   | showCursorKind (FileCursor(cf,fg,NONE))        =
-    "{@" ^ cf ^ " " ^ (showCol fg) ^ "}"
+    "{@" ^ cf ^ " " ^ (showColor fg) ^ "}"
   | showCursorKind (FileCursor(cf,fg,SOME(mf,bg))) =
-    "{@" ^ cf ^ " " ^ mf ^ " " ^ (showCol fg) ^ " " ^ (showCol bg) ^ "}"
+    "{@" ^ cf ^ " " ^ mf ^ " " ^ (showColor fg) ^ " " ^ (showColor bg) ^ "}"
 
 (* Added by E.L.Gunter 14 July 1998 *)
 fun showArrowPos NoneAP = "none"
@@ -429,8 +429,8 @@
   | showConf _ (Height n)          = " -height " ^ StringUtil.fromInt n
   | showConf _ (Borderwidth n)     = " -borderwidth " ^ StringUtil.fromInt n
   | showConf _ (Relief r)          = " -relief " ^ showRel r
-  | showConf _ (Foreground r)      = " -foreground " ^ showCol r
-  | showConf _ (Background r)      = " -background " ^ showCol r
+  | showConf _ (Foreground r)      = " -foreground " ^ showColor r
+  | showConf _ (Background r)      = " -background " ^ showColor r
   | showConf _ (Text t)            =
     " -text \"" ^ StringUtil.adaptString t ^ "\""
   | showConf _ (Font r)            = " -font " ^ Fonts.fontDescr r
@@ -441,8 +441,8 @@
   | showConf (w, p) (Command c)    =
     " -command {" ^ Com.commToTcl ^ "  \"Command " ^ w ^ " " ^ p ^ "\"}"
   | showConf _ (Anchor a)          = " -anchor " ^ showAnchorKind a
-  | showConf _ (FillColor r)       = " -fill " ^ showCol r
-  | showConf _ (Outline r)         = " -outline " ^ showCol r
+  | showConf _ (FillColor r)       = " -fill " ^ showColor r
+  | showConf _ (Outline r)         = " -outline " ^ showColor r
   | showConf _ (OutlineWidth n)    = " -width " ^ StringUtil.fromInt n
 (*| showconf _ (Stipple)           = ...*)
   | showConf _ (Smooth true)       = " -smooth true"
@@ -490,7 +490,7 @@
     " -command {" ^ Com.commToTcl' ^ "  \"SCommand " ^ w ^ " " ^ p ^ "\"}"
   | showConf _ (RepeatDelay i)     = " -repeatdelay " ^ StringUtil.fromInt i
   | showConf _ (RepeatInterval i)  = " -repeatinterval " ^ StringUtil.fromInt i
-  | showConf _ (ThroughColor c)    = " -throughcolor " ^ showCol c
+  | showConf _ (ThroughColor c)    = " -throughcolor " ^ showColor c
   | showConf _ (InnerPadX i)       = " -padx " ^ StringUtil.fromInt i
   | showConf _ (InnerPadY i)       = " -pady " ^ StringUtil.fromInt i
   | showConf _ (Show c)            = " -show " ^ Char.toString c
@@ -555,8 +555,8 @@
     " -command {" ^ Com.commToTcl ^" \"MCommand " ^ w ^ " " ^ p ^ " " 
     ^ (packCascPath m) ^ "\"}"
   | showMConf _ _ (Font f)         = " -font " ^ Fonts.fontDescr f
-  | showMConf _ _ (Foreground r)   = " -foreground " ^ showCol r
-  | showMConf _ _ (Background r)   = " -background " ^ showCol r
+  | showMConf _ _ (Foreground r)   = " -foreground " ^ showColor r
+  | showMConf _ _ (Background r)   = " -background " ^ showColor r
   | showMConf _ _ _                =
     raise CONFIG ("Config.showMConf: got wrong Config")
  
