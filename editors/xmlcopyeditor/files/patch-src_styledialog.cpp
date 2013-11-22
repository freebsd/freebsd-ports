--- src/styledialog.cpp.orig	2013-11-21 15:48:45.000000000 +0100
+++ src/styledialog.cpp	2013-11-21 15:50:28.000000000 +0100
@@ -705,7 +705,7 @@
 
 	WrapExpat we;
 	ofs << "<table><tr><th>Term</th><th>Frequency</th></tr>";
-	std::map<std::string, int>::iterator mapIterator;
+	std::map<std::string, int, NoCaseCompare>::iterator mapIterator;
 	int matchTotal = 0;
 
 	for (
