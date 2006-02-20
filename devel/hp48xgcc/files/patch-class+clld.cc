--- class/clld.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/clld.cc	4 Nov 2004 10:58:04 -0000	1.2
@@ -130,7 +130,7 @@
 	BIstream f;
 	f.open(name, ios::in | ios::binary);
 #else
-	ifstream f(name, ios::in | ios::bin);
+	ifstream f(name, ios::in | ios::binary);
 #endif
 	if (f.fail()) {
 	  if (!library)
@@ -332,7 +332,7 @@
 		BOstream shl_stream;
 		shl_stream.open ( shl_name, ios::out | ios::bin | ios::trunc );
 #else
-		ofstream shl_stream(shl_name, ios::out | ios::bin | ios::trunc );
+		ofstream shl_stream(shl_name, ios::out | ios::binary | ios::trunc );
 #endif
 		if (shl_stream.fail()) {
 			cerr << "ERROR: unable to open file '"+shl_name+"' for writing\n";
@@ -528,7 +528,7 @@
 	BOstream dst_stream;
 	dst_stream.open (bin_name, ios::out | ios::bin | ios::trunc );
 #else
-	ofstream dst_stream(bin_name, ios::out | ios::bin | ios::trunc );
+	ofstream dst_stream(bin_name, ios::out | ios::binary | ios::trunc );
 #endif
 	if (dst_stream.fail()) {
 		cerr << "ERROR: unable to open file '"+bin_name+"' for writing\n";
