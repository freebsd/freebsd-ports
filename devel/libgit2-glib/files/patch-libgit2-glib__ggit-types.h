--- libgit2-glib/ggit-types.h.orig	2015-01-23 16:20:26.456073499 +0100
+++ libgit2-glib/ggit-types.h	2015-01-23 16:20:00.476074798 +0100
@@ -1064,8 +1064,7 @@
 	GGIT_DIFF_FIND_COPIES_FROM_UNMODIFIED     = (1u << 3),
 	GGIT_DIFF_FIND_REWRITES                   = (1u << 4),
 	GGIT_DIFF_BREAK_REWRITES                  = (1u << 5),
-	GGIT_DIFF_FIND_AND_BREAK_REWRITES         = (GGIT_DIFF_FIND_REWRITES |
-	                                             GGIT_DIFF_BREAK_REWRITES),
+	GGIT_DIFF_FIND_AND_BREAK_REWRITES         = (GGIT_DIFF_FIND_REWRITES | GGIT_DIFF_BREAK_REWRITES),
 	GGIT_DIFF_FIND_FOR_UNTRACKED              = (1u << 6),
 	GGIT_DIFF_FIND_ALL                        = (0x0ff),
 	GGIT_DIFF_FIND_IGNORE_LEADING_WHITESPACE  = 0,
