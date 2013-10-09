--- class/LKV/StrIO.cc.orig	1995-06-24 08:36:46.000000000 +0400
+++ class/LKV/StrIO.cc	2013-10-09 13:03:54.000000000 +0400
@@ -3,11 +3,11 @@
 
 #include "set_error.h"
 
-#include <iostream.h>
+#include <iostream>
 
 #pragma implementation
 
-ostream & operator<< (ostream & o, const Str & s) {
+std::ostream & operator<< (std::ostream & o, const Str & s) {
 	o << ((const char *)s);
 	if (o.fail()) {
 		set_error("BOstream << Str ","stream output failed");
@@ -15,7 +15,7 @@ ostream & operator<< (ostream & o, const
 	return o;
 }
 
-istream & operator>> (istream & i, Str & s) {
+std::istream & operator>> (std::istream & i, Str & s) {
 	static char linebuf[1024];
 	
 	linebuf[1023] = (char)0;
