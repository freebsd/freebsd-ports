--- lib/qtag.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qtag.cc	Fri Feb 13 19:17:38 2004
@@ -2,6 +2,8 @@
  * implementation functions for class qtag
  */
 
+#include <iostream>
+
 # include "qtag.hh"
 # include "qmisc.hh"
 # include "qexception.hh"
@@ -118,8 +120,13 @@
 
 
 void qtag::print (ostream *os) {
-
-  os->form ("%-0.30s - %-0.30s - %-0.30s",tag->artist,tag->album,tag->title);
+  os->width(30);
+  *os << tag->artist << " - ";
+  os->width(30);
+  *os << tag->album << " - ";
+  os->width(30);
+  *os << tag->title;
+//  os->form ("%-0.30s - %-0.30s - %-0.30s",tag->artist,tag->album,tag->title);
 }
 
 
