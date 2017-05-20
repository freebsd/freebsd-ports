--- src/OracleAction.cc.orig	2017-05-07 11:14:19 UTC
+++ src/OracleAction.cc
@@ -222,7 +222,7 @@ void OracleAction::readChain()
 
 void OracleAction::backChar() 
 {
-    if ( _pC > 0 )
+    if ( _pC != 0 )
 	_pC--;
 }
     
