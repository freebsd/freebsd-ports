--- xa_vid_codec.c.orig	Sun Apr 21 01:20:46 2002
+++ xa_vid_codec.c	Thu Jan  2 07:30:36 2003
@@ -169,7 +169,9 @@
   if ((mod_path == 0) || (*mod_path==0))
 			mod_path = "/usr/local/xanim/mods";
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ModPath: %s\n",mod_path);/*CLEAN*/
+#endif
 
   len = strlen( mod_path );
   what_fun = (double)cos(45.0);
@@ -186,7 +188,9 @@
 
   dp = path_buf;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"PathBuf: %s\n",dp);/*CLEAN*/
+#endif
 
   while( dp && *dp )
   { char *t1p, *t2p;
@@ -211,10 +215,14 @@
   char *end_of_dir;
   int len;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ScanDir: a\n");/*CLEAN*/
+#endif
   if (dir_name == 0) return;
 
+#ifndef __FreeBSD__
   fprintf(stderr,"ScanDir: %s\n",dir_name);/*CLEAN*/
+#endif
 
   DEBUG_LEVEL1 fprintf(stderr,"dirname: %s\n", dir_name );
 
