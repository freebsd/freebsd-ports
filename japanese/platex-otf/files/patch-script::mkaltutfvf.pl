--- script/mkaltutfvf.pl.orig	Wed Feb 25 03:58:16 2004
+++ script/mkaltutfvf.pl	Sat Aug 21 20:28:56 2004
@@ -37,7 +37,7 @@
 				}
 				&writechar;
 				close(OVP);
-				system("ovp2ovf ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
+				system("ovp2ovf-old ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
 				unlink "vf/$filename.ofm";
 			}
 		}
