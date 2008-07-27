--- lib/TChDirDialog.cc.orig	2008-07-27 18:48:30.000000000 +0200
+++ lib/TChDirDialog.cc	2008-07-27 18:49:16.000000000 +0200
@@ -103,7 +103,7 @@
 #ifndef __UNPATCHED
 		//!! Handle directory selection.
                 case cmDirSelection:
-                    chDirButton->makeDefault( Boolean( int(
+                    chDirButton->makeDefault( Boolean( intptr_t( 
 			event.message.infoPtr ) ) );
                     return;     // NOTE: THIS IS RETURN NOT BREAK!!
 #endif
