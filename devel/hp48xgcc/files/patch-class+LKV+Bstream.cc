--- class/LKV/Bstream.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Bstream.cc	3 Nov 2004 11:24:06 -0000	1.2
@@ -10,15 +10,15 @@ extern "C" {
 #include "Bstream.h"
 
 #ifndef OBSOLETE_LIBGXX
-BOstream::BOstream ( ostream & orig ) : ostream(orig.rdbuf()) {
-	ostream::setf(ios::scientific);
-	ostream::precision(190);
+BOstream::BOstream ( std::ostream & orig ) : std::ostream(orig.rdbuf()) {
+	std::ostream::setf(std::ios::scientific);
+	std::ostream::precision(190);
 }
 #endif
 
 void BOstream::ewrite(const void * p, int size) {
-	write ((const unsigned char *)p, size);
-	if (ostream::fail()) {
+	write ((const char *)p, size);
+	if (std::ostream::fail()) {
 		set_error("BOstream::operator<< ","write-error");
 	}
 }
@@ -28,14 +28,14 @@ void BOstream::ewrite(const void * p, in
 // ==============================================================
 
 #ifndef OBSOLETE_LIBGXX
-BIstream::BIstream( istream & orig ) : istream(orig.rdbuf()) {
+BIstream::BIstream( std::istream & orig ) : std::istream(orig.rdbuf()) {
 
 }
 #endif
 
 void BIstream::eread(void * p, int size) {
-	read ((unsigned char *)p, size);
-	if (istream::fail()) {
+	read ((char *)p, size);
+	if (std::istream::fail()) {
 		set_error("BIstream::operator>> ","read-error");
 	}
 }
