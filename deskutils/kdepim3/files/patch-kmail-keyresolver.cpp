--- kmail/keyresolver.cpp.orig	Thu Nov 10 05:39:42 2005
+++ kmail/keyresolver.cpp	Thu Nov 10 05:48:08 2005
@@ -1023,8 +1023,10 @@
   CryptoMessageFormat commonFormat = AutoFormat;
 
   for ( unsigned int i = 0 ; i < numConcreteCryptoMessageFormats ; ++i ) {
+    if ( !(mCryptoMessageFormats & concreteCryptoMessageFormats[i]) ) 
+      continue; // skip 
     if ( signingKeysFor( concreteCryptoMessageFormats[i] ).empty() )
-      continue; // skip;
+      continue; // skip
     if ( count.numOf( concreteCryptoMessageFormats[i] ) == count.numTotal() ) {
       commonFormat = concreteCryptoMessageFormats[i];
       break;
