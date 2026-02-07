--- mapm/npt_cmds.c.orig	1993-02-09 16:35:04 UTC
+++ mapm/npt_cmds.c
@@ -78,7 +78,7 @@ command draw_map()
     nomore_args(num_args);
 
     run {
-	if (!make_filename(name,FORCE_EXTENSION,PS_EXT))
+	if (!make_filename(name,FORCE_EXTENSION,WRS(PS_EXT)))
 	  { sf(ps,"illegal filename '%s'",name); error(ps); }
 	fp= open_file(name,WRITE);
 	sf(ps,"Drawing map in PostScript file '%s'... \n",name); pr();
