--- src/latexgen.cpp.orig	Mon Sep  2 22:01:34 2002
+++ src/latexgen.cpp	Sun May 11 15:04:45 2003
@@ -286,7 +286,7 @@
   }
   t << "\\makeindex\n"
     "\\setcounter{tocdepth}{1}\n"
-    "\\setlength{\\footrulewidth}{0.4pt}\n"
+    "\\renewcommand{\\footrulewidth}{0.4pt}\n"
     "\\begin{document}\n";
   if (theTranslator->idLanguage()=="greek") t << "\\selectlanguage{greek}\n";
   t << "\\begin{titlepage}\n"
