--- haddock/src/HaddockUtil.hs.orig	Tue Feb  1 22:15:52 2005
+++ haddock/src/HaddockUtil.hs	Tue Feb  1 22:35:29 2005
@@ -188,12 +188,7 @@
 
 moduleHeaderRE :: Regex
 moduleHeaderRE = mkRegexWithOpts
-			 "^([ \t\n]*Module[ \t]*:.*\n)?\ 
-			  \([ \t\n]*Copyright[ \t]*:.*\n)?\ 
-			  \([ \t\n]*License[ \t]*:.*\n)?\ 
-			  \[ \t\n]*Maintainer[ \t]*:(.*)\n\ 
-			  \[ \t\n]*Stability[ \t]*:(.*)\n\ 
-			  \[ \t\n]*Portability[ \t]*:([^\n]*)\n"
+			 "^([ \t\n]*Module[ \t]*:.*\n)?([ \t\n]*Copyright[ \t]*:.*\n)?([ \t\n]*License[ \t]*:.*\n)?[ \t\n]*Maintainer[ \t]*:(.*)\n[ \t\n]*Stability[ \t]*:(.*)\n[ \t\n]*Portability[ \t]*:([^\n]*)\n"
 		True -- match "\n" with "."
 		False -- not case sensitive
 	-- All fields except the last (Portability) may be multi-line.
