--- src/common/global/global.h.orig	2013-11-16 13:33:38.000000000 +0100
+++ src/common/global/global.h	2013-11-16 13:34:08.000000000 +0100
@@ -684,8 +684,8 @@
 			file.WriteLine("\t", false);
 		else
 			file.WriteLine(", ", false);
-		file.WriteLine("[" + NumberToString(inv[i]->GetID()) + "] = "
-			+ NumberToString(inv[i]->GetCount()), false);
+		file.WriteLine("[" + hoa_utils::NumberToString(inv[i]->GetID()) + "] = "
+			+ hoa_utils::NumberToString(inv[i]->GetCount()), false);
 	}
 	file.InsertNewLine();
 	file.WriteLine("}");
