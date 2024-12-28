--- src/cmd/cmd.c.orig	2024-12-28 13:13:41 UTC
+++ src/cmd/cmd.c
@@ -179,9 +179,9 @@ gcli_pretty_print(char const *input, int indent, int m
 	if (!gcli_config_have_colours(g_clictx))
 		opts.oflags |= (LOWDOWN_TERM_NOANSI|LOWDOWN_TERM_NOCOLOUR);
 
-	opts.vmargin = 1;
-	opts.hmargin = indent - 4; /* somehow there's always 4 spaces being emitted by lowdown */
-	opts.cols = maxlinelen;
+	opts.term.vmargin = 1;
+	opts.term.hmargin = indent - 4; /* somehow there's always 4 spaces being emitted by lowdown */
+	opts.term.cols = maxlinelen;
 
 	if ((doc = lowdown_doc_new(&opts)) == NULL)
 		err(1, NULL);
