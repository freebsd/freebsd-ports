--- lib/qwav.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qwav.cc	Fri Feb 13 19:17:38 2004
@@ -2,6 +2,8 @@
  * implementation functions for class qwav
  */
 
+#include <iostream>
+
 # include "qwav.hh"
 # include "qexception.hh"
 
@@ -37,16 +39,28 @@
   msduration = getMsDuration();
 
  // cal posar les milèssimes?
+  *os << getName() << ": " << getSampleRate() << " Hz  "
+      << getBitsPerSample() << " bits  "
+      << ((getChannels()==1)?"mono":"stereo") << ' ';
+  os->width(2);
+  *os << msduration/60000 << ':';
+  os->width(2);
+  os->fill('0');
+  *os << (msduration/1000)%60 << '.';
+  os->width(2);
+  os->fill('0');
+  *os << (msduration%1000)/10;
+  /*
   os->form("%s: %u Hz  %u bits  %s  %2u:%02u.%02u",
 	   getName().c_str(),
            getSampleRate(),getBitsPerSample(),
            ((getChannels()==1)?"mono":"stereo"),
            msduration/60000,(msduration/1000)%60,(msduration%1000)/10);
-
+  */
 }
 
 
-qwav::qwav(string name, u_int32_t flags=READ) 
+qwav::qwav(string name, u_int32_t flags) 
      : qfile (name,flags), 
        qwavheader(getMap(),getSize()) { 
 
