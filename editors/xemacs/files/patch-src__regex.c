--- ./src/regex.c.orig	2006-03-31 01:29:00.000000000 +0000
+++ ./src/regex.c	2009-12-10 06:16:16.198040087 +0000
@@ -3106,9 +3107,6 @@
 	normal_char:
 	  {
 	    /* XEmacs: modifications here for Mule. */
-	    /* `q' points to the beginning of the next char. */
-	    re_char *q = p;
-
 	    /* If no exactn currently being built.  */
 	    if (!pending_exact
 
@@ -3116,18 +3114,17 @@
 		|| pending_exact + *pending_exact + 1 != buf_end
 
 		/* We have only one byte following the exactn for the count. */
-		|| ((unsigned int) (*pending_exact + (q - p)) >=
-		    ((unsigned int) (1 << BYTEWIDTH) - 1))
+		|| *pending_exact >= (1 << BYTEWIDTH) - 1
 
 		/* If followed by a repetition operator.  */
-		|| *q == '*' || *q == '^'
+                || (p != pend && (*p == '*' || *p == '^'))
 		|| ((syntax & RE_BK_PLUS_QM)
-		    ? *q == '\\' && (q[1] == '+' || q[1] == '?')
-		    : (*q == '+' || *q == '?'))
+		    ? p + 1 < pend && *p == '\\' && (p[1] == '+' || p[1] == '?')
+		    : p != pend && (*p == '+' || *p == '?'))
 		|| ((syntax & RE_INTERVALS)
 		    && ((syntax & RE_NO_BK_BRACES)
-			? *q == '{'
-			: (q[0] == '\\' && q[1] == '{'))))
+			? p != pend && *p == '{'
+			: p + 1 < pend && (p[0] == '\\' && p[1] == '{'))))
 	      {
 		/* Start building a new exactn.  */
 
