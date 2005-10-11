--- src/view/telnetview.cpp.orig	Tue Oct 11 02:44:46 2005
+++ src/view/telnetview.cpp	Tue Oct 11 02:45:04 2005
@@ -334,7 +334,7 @@
 				strncmp(t_pcDot, "tbz", 3) == 0)
 			{
 				string t_sURL = sURL;
-				t_sURL.insert(0, "wget ");
+				t_sURL.insert(0, "fetch ");
 				t_sURL.append(" &");
 				system(t_sURL.c_str());
 				return;
