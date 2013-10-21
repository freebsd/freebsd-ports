--- src/rcsrev.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcsrev.c	1999-08-28 03:37:10.000000000 +0400
@@ -883,17 +882,17 @@ int argc; char * argv[];
                 /* all output goes to stderr, to have diagnostics and       */
                 /* errors in sequence.                                      */
 		aputs("\nEnter revision number or <return> or '.': ",stderr);
-		if (!gets(symrevno)) break;
+		if (!fgets(symrevno, 100, stdin)) break;
                 if (*symrevno == '.') break;
 		aprintf(stderr,"%s;\n",symrevno);
 		expandsym(symrevno,&numricrevno);
 		aprintf(stderr,"expanded number: %s; ",numricrevno.string);
 		aprintf(stderr,"Date: ");
-		gets(date); aprintf(stderr,"%s; ",date);
+		fgets(date, 20, stdin); aprintf(stderr,"%s; ",date);
 		aprintf(stderr,"Author: ");
-		gets(author); aprintf(stderr,"%s; ",author);
+		fgets(author, 20, stdin); aprintf(stderr,"%s; ",author);
 		aprintf(stderr,"State: ");
-		gets(state); aprintf(stderr, "%s;\n", state);
+		fgets(state, 20, stdin); aprintf(stderr, "%s;\n", state);
 		target = genrevs(numricrevno.string, *date?date:(char *)0, *author?author:(char *)0,
 				 *state?state:(char*)0, &gendeltas);
 		if (target) {
