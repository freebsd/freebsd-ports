--- ./Criterion/Main.hs.orig	2010-03-30 00:56:34.000000000 +0200
+++ ./Criterion/Main.hs	2010-06-07 11:28:30.097091827 +0200
@@ -58,8 +58,7 @@
 import System.Console.GetOpt
 import System.Environment (getArgs, getProgName)
 import System.Exit (ExitCode(..), exitWith)
-import Text.Parsec
-import Text.Parsec.String
+import Text.ParserCombinators.Parsec
 
 -- | Parse a plot output.
 parsePlot :: Parser PlotOutput
