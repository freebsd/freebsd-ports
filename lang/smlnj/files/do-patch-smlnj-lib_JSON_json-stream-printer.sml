--- smlnj-lib/JSON/json-stream-printer.sml.orig	2017-07-14 22:32:40.000000000 +0200
+++ smlnj-lib/JSON/json-stream-printer.sml	2017-10-25 20:33:53.541874000 +0200
@@ -103,14 +103,14 @@
 	  fun tr (i, chrs) = (case getWChar i
 		 of SOME(wchr, i) => if (wchr <= 0w126)
 		      then (case UTF8.toAscii wchr
-			 of #"\"" => "\\\""
-			  | #"\\" => "\\\\"
-			  | #"/" => "\\/"
-			  | #"\b" => "\\b"
-			  | #"\f" => "\\f"
-			  | #"\n" => "\\n"
-			  | #"\r" => "\\r"
-			  | #"\t" => "\\t"
+			 of #"\"" => tr(i, "\\\"" :: chrs)
+			  | #"\\" => tr(i, "\\\\" :: chrs)
+			  | #"/" => tr(i, "\\/" :: chrs)
+			  | #"\b" => tr(i, "\\b" :: chrs)
+			  | #"\f" => tr(i, "\\f" :: chrs)
+			  | #"\n" => tr(i, "\\n" :: chrs)
+			  | #"\r" => tr(i, "\\r" :: chrs)
+			  | #"\t" => tr(i, "\\t" :: chrs)
 			  | c => if (wchr < 0w32)
 			      then tr(i, F.format "\\u%04x" [F.WORD wchr] :: chrs)
 			      else tr(i, str c :: chrs)
