--- Build.PL.orig	2023-03-24 10:09:57 UTC
+++ Build.PL
@@ -23,7 +23,6 @@ Module::Build->new(
 		"warnings" => 0,
 	},
 	requires => {
-		"Lexical::SealRequireHints" => "0.012",
 		"XSLoader" => 0,
 		"perl" => "5.006",
 		"strict" => 0,
