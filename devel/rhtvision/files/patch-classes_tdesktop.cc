--- classes/tdesktop.cc.orig	2017-08-18 14:40:03 UTC
+++ classes/tdesktop.cc
@@ -26,6 +26,11 @@ Modified cursor behavior while desktop locked by Salva
 #define Uses_TVCodePage
 #include <tv.h>
 
+inline unsigned int absdiff(unsigned int a, unsigned int b)
+{
+    return (a>=b)?a-b:b-a;
+}
+
 TDeskInit::TDeskInit( TBackground *(*cBackground)( TRect ) ) :
     createBackground( cBackground )
 {
@@ -144,7 +149,7 @@ unsigned iSqr( unsigned i )
 {
     unsigned res1 = 2;
     unsigned res2 = i/res1;
-    while( abs( res1 - res2 ) > 1 )
+    while( absdiff(res1,res2) > 1 )
         {
         res1 = (res1 + res2)/2;
         res2 = i/res1;
