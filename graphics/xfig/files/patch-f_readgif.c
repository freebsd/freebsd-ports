--- f_readgif.c.orig	Tue Jul 26 09:39:59 2005
+++ f_readgif.c
@@ -175,7 +175,7 @@
 	/* make name for temp output file */
 	sprintf(pcxname, "%s/%s%06d.pix", TMPDIR, "xfig-pcx", getpid());
 	/* make command to convert gif to pcx into temp file */
-	sprintf(buf, "giftopnm | ppmtopcx > %s 2> /dev/null", pcxname);
+	sprintf(buf, "giftopnm -quiet | ppmtopcx -quiet > %s", pcxname);
 	if ((giftopcx = popen(buf,"w" )) == 0) {
 	    file_msg("Cannot open pipe to giftopnm or ppmtopcx\n");
 	    close_picfile(file,filetype);
