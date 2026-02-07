--- hclib.c.orig	2011-09-05 14:36:04.000000000 +0800
+++ hclib.c	2011-09-05 14:38:30.000000000 +0800
@@ -155,7 +155,7 @@ static void add(a1, am, i, code)
     else if (am[i])			/* already has multiple mappings */
     {
 	/* Check multiple mapping list, if there, return. */
-	while (x=am[i][n])
+	while ((x = am[i][n]))
 	{
 	    if (x==code) return;
 	    else n++;
@@ -191,17 +191,17 @@ static int do_line (lcnt, buffer)
 
     if (!inGBrange(gb_code))
     {
-	fprintf(stderr, "Invalid GB code in line %d\n", lcnt);
+	fprintf(stderr, "Invalid GB code in line %ld\n", lcnt);
 	return(0);
     }
-    while (c1=buffer[i++])
+    while ((c1 = buffer[i++]))
     {
 	c2 = buffer[i++];
 	if (!(c1&&c2)) break;
 	big_code = DB(c1,c2);
 	if (!inBIGrange(big_code))
 	{
-	    fprintf(stderr, "Invalid BIG5 code in line %d\n", lcnt);
+	    fprintf(stderr, "Invalid BIG5 code in line %ld\n", lcnt);
 	    return(0);
 	}
 	add(GtoB, mGtoB, gb_code - GBfirst, big_code);
@@ -261,7 +261,7 @@ static int cvrt(a1, am, i, result, n)
     if (codeDes == 0) return(0);
     result[0] = codeDes;
     if (am[i])
-	while (x = am[i][k])
+	while ((x = am[i][k]))
 	{
 	    if (k>=n) break;
 	    result[++k] = x;
