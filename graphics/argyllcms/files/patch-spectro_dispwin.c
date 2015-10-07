Description: Add check for NULL pointer
Author: Jörg Frings-Fürst <debian@jff-webhsoting.net>
Bug-Debian: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=700253
Forwarded: http://www.freelists.org/post/argyllcms/dispwin-bad-command-line-option-makes-dispwin-segfault
Reviewed-by: 
Last-Update: 2014-09-14
---
--- spectro/dispwin.c.orig	2015-05-01 10:15:55.000000000 +0200
+++ spectro/dispwin.c	2015-08-09 14:48:49.778919000 +0200
@@ -5547,6 +5547,7 @@
 
 			/* Display number */
 			else if (argv[fa][1] == 'd') {
+				if(na == NULL)  usage(0,"-d parameter missing");
 				if (strncmp(na,"web",3) == 0
 				 || strncmp(na,"WEB",3) == 0) {
 					webdisp = 8080;
