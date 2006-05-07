--- plugins/vidinput_bsd/vidinput_bsd.cxx.orig	Tue Aug  9 11:08:09 2005
+++ plugins/vidinput_bsd/vidinput_bsd.cxx	Wed Apr  5 21:35:08 2006
@@ -122,12 +122,11 @@
 #pragma implementation "vidinput_bsd.h"
 
 #include "vidinput_bsd.h"
-#include <sys/mman.h>
 
 PCREATE_VIDINPUT_PLUGIN(BSDCAPTURE);
 
 ///////////////////////////////////////////////////////////////////////////////
-// PVideoInputDevice_BSDCAPTURE
+// PVideoInputBSDCAPTURE
 
 PVideoInputDevice_BSDCAPTURE::PVideoInputDevice_BSDCAPTURE()
 {
@@ -142,6 +141,7 @@
 
 BOOL PVideoInputDevice_BSDCAPTURE::Open(const PString & devName, BOOL startImmediate)
 {
+  if (IsOpen())
   Close();
 
   deviceName = devName;
@@ -235,10 +235,14 @@
 {
   PStringList list;
 
-  list.AppendString("/dev/bktr0");
-  list.AppendString("/dev/bktr1");
-  list.AppendString("/dev/meteor0");
-  list.AppendString("/dev/meteor1");
+  if (PFile::Exists("/dev/bktr0"))
+    list.AppendString("/dev/bktr0");
+  if (PFile::Exists("/dev/bktr1"))
+    list.AppendString("/dev/bktr1");
+  if (PFile::Exists("/dev/meteor0"))
+    list.AppendString("/dev/meteor0");
+  if (PFile::Exists("/dev/meteor1"))
+    list.AppendString("/dev/meteor1");
 
   return list;
 }
