--- lib/qmp3.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qmp3.cc	Fri Feb 13 19:17:38 2004
@@ -2,6 +2,10 @@
  * implementation functions for class qmp3
  */
 
+using namespace std;
+
+#include <iostream>
+
 # include "qmp3.hh"
 # include "qexception.hh"
 # include "qmisc.hh"
@@ -67,7 +71,7 @@
 }
 
 
-qmp3::qmp3(string name, u_int32_t flags=READ)
+qmp3::qmp3(string name, u_int32_t flags)
      : qfile (name,flags),
        qmp3frameheader (qfile::getMap()),
        qtag (qfile::getMap()+getSize()-qtag::LENGTH) {
@@ -114,7 +118,7 @@
   return false;
 }
 
-u_int32_t qmp3::scan (u_int32_t bufsize=0) {
+u_int32_t qmp3::scan (u_int32_t bufsize) {
 
   if (!bufsize)
     bufsize = getStreamLength(); 
@@ -178,8 +182,13 @@
     *os << "[vbr]";
 
   msduration = getMsDuration();
-  os->form("  %d:%02d.%03d  ",
-           msduration/60000,(msduration/1000)%60,msduration%1000); 
+  *os << "  " << msduration/60000 << ":";
+  os->width(2);
+  os->fill('0');
+  *os << (msduration/1000)%60 << '.';
+  os->width(3);
+  os->fill('0');
+  *os << msduration%1000 << "  ";
 
   if (hasTag) 
     this->qtag::print(os);
