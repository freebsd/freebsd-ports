--- mapm/npt_cmds.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/npt_cmds.c	2008-03-27 21:27:12.000000000 +0000
@@ -78,7 +78,7 @@
     nomore_args(num_args);
 
     run {
-	if (!make_filename(name,FORCE_EXTENSION,PS_EXT))
+	if (!make_filename(name,FORCE_EXTENSION,WRS(PS_EXT)))
 	  { sf(ps,"illegal filename '%s'",name); error(ps); }
 	fp= open_file(name,WRITE);
 	sf(ps,"Drawing map in PostScript file '%s'... \n",name); pr();
