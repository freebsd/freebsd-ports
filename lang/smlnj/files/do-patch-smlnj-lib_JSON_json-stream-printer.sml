--- smlnj-lib/JSON/json-stream-printer.sml.orig	2017-07-14 20:32:40 UTC
+++ smlnj-lib/JSON/json-stream-printer.sml
@@ -103,14 +103,14 @@ structure JSONStreamPrinter : sig
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
