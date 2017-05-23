Description: Add check for NULL pointer
Author: Jörg Frings-Fürst <debian@jff-webhsoting.net>
Bug-Debian: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=700253
Forwarded: http://www.freelists.org/post/argyllcms/dispwin-bad-command-line-option-makes-dispwin-segfault
Reviewed-by: 
Last-Update: 2014-09-14
--- spectro/dispwin.c.orig	2016-09-28 02:59:10 UTC
+++ spectro/dispwin.c
@@ -6055,6 +6055,7 @@ main(int argc, char *argv[]) {
 
 			/* Display number */
 			else if (argv[fa][1] == 'd') {
+				if(na == NULL)  usage(0,"-d parameter missing");
 				if (strncmp(na,"web",3) == 0
 				 || strncmp(na,"WEB",3) == 0) {
 					webdisp = 8080;
