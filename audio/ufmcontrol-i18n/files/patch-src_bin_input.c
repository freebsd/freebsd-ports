--- src/bin/input.c.orig	2014-08-06 20:09:27 UTC
+++ src/bin/input.c
@@ -51,7 +51,7 @@ input(int *cmd)
 				#if __FreeBSD_version >= 500000
 					&he,
 				#endif
-					H_EVENT, 100);
+					H_SETSIZE, 100);
 				el_set(el, EL_HIST, history, hist);
 				el_set(el, EL_EDITOR, "emacs");
 				el_set(el, EL_PROMPT, ufmcontrol_prompt);
