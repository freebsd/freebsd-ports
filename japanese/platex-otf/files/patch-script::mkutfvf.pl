--- script/mkutfvf.pl.orig	Wed Feb 25 03:52:46 2004
+++ script/mkutfvf.pl	Sat Aug 21 20:30:45 2004
@@ -22,7 +22,7 @@
 					&fontfoot;
 					&writechar;
 					close(OUT);
-					system("ovp2ovf ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
+					system("ovp2ovf-old ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
 					unlink "vf/$filename.ofm";
 				}
 			}
@@ -46,7 +46,7 @@
 					&fontfoot;
 					&writechar;
 					close(OUT);
-					system("ovp2ovf ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
+					system("ovp2ovf-old ovp/$filename.ovp vf/$filename.vf vf/$filename.ofm");
 					unlink "vf/$filename.ofm";
 				}
 			}
