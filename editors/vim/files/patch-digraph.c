
$FreeBSD$

--- digraph.c	2003/10/29 10:29:14	1.1
+++ digraph.c	2003/10/29 10:29:43
@@ -2175,7 +2175,7 @@
 	str = skipwhite(str);
 	if (!isdigit(*str))
 	{
-	    EMSG(_(e_number));
+	    EMSG(_(e_numbe));
 	    return;
 	}
 	n = getdigits(&str);
