--- script/mkcidvf.pl.orig	Wed Feb 25 03:52:02 2004
+++ script/mkcidvf.pl	Sat Aug 21 20:29:50 2004
@@ -18,7 +18,7 @@
 				&fontfoot;
 				&writechar;
 				close(OUT);
-				system("ovp2ovf ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
+				system("ovp2ovf-old ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
 				unlink "vf/$filename.ofm";
 			}
 		}
