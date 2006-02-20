--- class/LKV/Bstream.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Bstream.cc	3 Nov 2004 11:24:06 -0000	1.2
@@ -17,7 +17,7 @@
 #endif
 
 void BOstream::ewrite(const void * p, int size) {
-	write ((const unsigned char *)p, size);
+	write ((const char *)p, size);
 	if (ostream::fail()) {
 		set_error("BOstream::operator<< ","write-error");
 	}
@@ -34,7 +34,7 @@
 #endif
 
 void BIstream::eread(void * p, int size) {
-	read ((unsigned char *)p, size);
+	read ((char *)p, size);
 	if (istream::fail()) {
 		set_error("BIstream::operator>> ","read-error");
 	}
