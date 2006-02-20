--- class/class.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/class.cc	4 Nov 2004 10:58:04 -0000	1.2
@@ -3310,7 +3310,7 @@
 	BOstream of;
 	of.open(obj.name, ios::out | ios::binary);
 #else
-	ofstream of( obj.name, ios::out | ios::bin );
+	ofstream of( obj.name, ios::out | ios::binary );
 #endif
 	if (of.fail()) {
 		cerr << "FATAL ERROR: unable to open output file '" << obj.name << "'\n";
