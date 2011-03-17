--- src/inspircd.cpp.orig	2010-12-11 15:07:45.000000000 +0900
+++ src/inspircd.cpp	2010-12-11 15:08:11.000000000 +0900
@@ -274,7 +274,7 @@
 {
 	std::string fname(filename);
 	if (fname.empty())
-		fname = "data/inspircd.pid";
+		fname = "/var/run/inspircd/inspircd.pid";
 	std::ofstream outfile(fname.c_str());
 	if (outfile.is_open())
 	{
