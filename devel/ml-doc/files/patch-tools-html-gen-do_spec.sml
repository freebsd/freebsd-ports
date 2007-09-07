--- tools/html-gen/do-spec.sml.orig	Sun Aug  5 20:42:32 2007
+++ tools/html-gen/do-spec.sml	Sun Aug  5 20:43:41 2007
@@ -82,7 +82,7 @@
 		   of (body, NONE) => HTML.CODE(T.codeToHTML ctx body)
 		    | (body, SOME result) => HTML.TextList[
 			  HTML.CODE(T.codeToHTML ctx body),
-			  HTML.EM(HTML.PCDATA "evaluates to"),
+			  HTML.EM(HTML.PCDATA " evaluates to "),
 			  HTML.CODE result
 			]
 		  (* end case *)
