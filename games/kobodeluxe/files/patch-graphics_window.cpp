--- graphics/window.cpp.orig	2007-12-14 09:13:24 UTC
+++ graphics/window.cpp
@@ -398,7 +398,7 @@ void window_t::center_token_fxp(int _x, 
 		 */
 		if(token)
 		{
-			char *tok = strchr(txt, token);
+			const char *tok = strchr(txt, token);
 			if(tok)
 				tokpos = tok-txt;
 			else
