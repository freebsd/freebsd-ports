--- src/cook.c.orig	Sat Dec 14 22:31:23 2002
+++ src/cook.c	Tue Jan  7 23:53:11 2003
@@ -106,7 +106,7 @@
 				space--;
 			}
 
-		} else if (((*p) & 0xFF) < ' ' && *p != '\n') {	/* Literal ctrl chars */
+		} else if (((*p) & 0xFF) < ' ' && *p != '\n' && *p != 27) {	/* Literal ctrl chars */
 			*q++ = '^';
 			if (--space) {
 				*q++ = ((*p) & 0xFF) + '@';
@@ -793,7 +793,7 @@
 		if (expand_ctrl_chars(to, line, sizeof(to) - 1, cook_width))
 			flags |= C_CTRLL;				/* Line contains form-feed */
 
-		put_cooked(wrap_lines, flags, "%s", to);
+		put_cooked(wrap_lines && strncasecmp(tinrc.mm_local_charset, "Big5", 4), flags, "%s", to);
 	} /* while */
 
 	/*
