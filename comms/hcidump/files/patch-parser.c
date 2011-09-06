--- parser/parser.c.ORIG	Fri Sep 22 23:33:36 2006
+++ parser/parser.c	Fri Sep 22 23:34:45 2006
@@ -65,7 +65,7 @@
 
 	if (!parser.state) {
 		if (parser.flags & DUMP_TSTAMP)
-			printf("%8lu.%06lu ", f->ts.tv_sec, f->ts.tv_usec);
+			printf("%8lu.%06lu ", (unsigned long)f->ts.tv_sec, f->ts.tv_usec);
 		printf("%c ", (f->in ? '>' : '<'));
 		parser.state = 1;
 	} else
