--- src/emucore/Props.cxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/Props.cxx	Wed Sep 17 00:42:05 2003
@@ -103,7 +103,7 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-void Properties::load(istream& in)
+void Properties::load(std::istream& in)
 {
   // Empty my property array
   mySize = 0;
@@ -146,7 +146,7 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-void Properties::save(ostream& out)
+void Properties::save(std::ostream& out)
 {
   // Write out each of the key and value pairs
   for(uInt32 i = 0; i < mySize; ++i)
@@ -164,7 +164,7 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-string Properties::readQuotedString(istream& in)
+string Properties::readQuotedString(std::istream& in)
 {
   char c;
 
@@ -205,7 +205,7 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-void Properties::writeQuotedString(ostream& out, const string& s)
+void Properties::writeQuotedString(std::ostream& out, const string& s)
 {
   out.put('"');
   for(uInt32 i = 0; i < s.length(); ++i)
