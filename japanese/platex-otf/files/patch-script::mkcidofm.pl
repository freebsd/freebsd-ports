--- script/mkcidofm.pl.orig	Sat Aug 21 20:33:58 2004
+++ script/mkcidofm.pl	Sat Aug 21 20:34:13 2004
@@ -63,6 +63,6 @@
 			print  OPL "   )\n";
 		}
 		close(OPL);
-		system("opl2ofm opl/$font_name.opl ofm/$font_name.ofm")
+		system("opl2ofm-old opl/$font_name.opl ofm/$font_name.ofm")
 	}
 }
