--- word.c.orig	2026-05-20 15:03:11 UTC
+++ word.c
@@ -209,12 +209,13 @@ grabword(char **word)

	while (inword() == TRUE) {
		if (cap == 0 || len == cap - 1) {
-			t = recallocarray(*word, cap, cap + 8, 1);
+			t = realloc(*word, cap + 8);
			if (t == NULL) {
				free(*word);
				*word = NULL;
				return (errno);
			}
+			memset(t + cap, 0, 8);
			cap += 8;
			*word = t;
		}
