--- script/mkpropofm.pl.orig	Sat Aug 21 20:35:04 2004
+++ script/mkpropofm.pl	Sat Aug 21 20:35:17 2004
@@ -81,6 +81,6 @@
 			print  OPL "   )\n";
 		}
 		close(OPL);
-		system("opl2ofm opl/$font_name.opl ofm/$font_name.ofm")
+		system("opl2ofm-old opl/$font_name.opl ofm/$font_name.ofm")
 	}
 }
