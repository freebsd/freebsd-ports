--- libr/core/vmenus.c.orig	2022-02-18 17:27:13 UTC
+++ libr/core/vmenus.c
@@ -3235,7 +3235,7 @@ R_API void r_core_visual_debugtraces(RCore *core, cons
 		//int rows = r_cons_get_size (NULL);
 		r_core_cmdf (core, "dtd %d", delta);
 		r_cons_visual_flush ();
-		char ch ;
+		signed char ch ;
 		if (input && *input) {
 			ch = *input;
 			input++;
