--- src/source.c.orig	1999-04-09 23:40:26 UTC
+++ src/source.c
@@ -250,7 +250,7 @@ static	const	char	*const	errname[] = {
 		abort();
 	if (errtype >= FATALERR) {
 		if (gen_listing)	/* copy the rest to the listing */
-			while (getline())
+			while (get_line())
 				;
 		(void)exit(1);
 	}
@@ -287,7 +287,7 @@ interactive(void)
  *	otherwise it ends in a newline (whitespace) and then a null.
  */
 global Bool
-getline(void)
+get_line(void)
 {
 	if (atend && cur_source >= source) {
 		if (cur_source > source)
