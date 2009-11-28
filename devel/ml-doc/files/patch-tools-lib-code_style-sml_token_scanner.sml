--- tools/lib/code-style/sml-token-scanner.sml.orig	2006-11-27 23:41:58.000000000 +0100
+++ tools/lib/code-style/sml-token-scanner.sml	2009-09-24 00:05:48.000000000 +0200
@@ -37,20 +37,20 @@
 
     val comElem : E.element option = SOME E.IT
 
-    fun startCom (M.Match(SOME{pos as {comLevel, data}, len}, _)) =
+    fun startCom (M.Match({pos as {comLevel, data}, len}, _)) =
 	  (comElem, prefix(len, pos), {comLevel=comLevel+1, data=SS.triml len data})
 
-    fun endCom (M.Match(SOME{pos as {comLevel, data}, len}, _)) =
+    fun endCom (M.Match({pos as {comLevel, data}, len}, _)) =
 	  (comElem, prefix(len, pos), {comLevel=comLevel-1, data=SS.triml len data})
 
-    fun ident (M.Match(SOME{pos, len}, _)) = let
+    fun ident (M.Match({pos, len}, _)) = let
 	  val txt = prefix(len, pos)
 	  val kind = if SMLKeywords.isKW txt then SOME E.KW else NONE
 	  in
 	    (kind, txt, trim(len, pos))
 	  end
 
-    fun mkToken (kind : E.element option) (M.Match(SOME{pos, len}, _)) =
+    fun mkToken (kind : E.element option) (M.Match({pos, len}, _)) =
 	  (kind, prefix(len, pos), trim(len, pos))
 
     val tyvar = mkToken NONE
@@ -60,7 +60,7 @@
     val entity = mkToken NONE
 
   (* string gets called after we have seen either #" or " *)
-    fun string (M.Match(SOME{pos, len}, _)) = let
+    fun string (M.Match({pos, len}, _)) = let
 	  fun getS (ss, n) = (case SS.getc ss
 		 of NONE => raise Fail "unclosed string"
 		  | SOME(#"\\", ss') => getS'(ss', n+1)
