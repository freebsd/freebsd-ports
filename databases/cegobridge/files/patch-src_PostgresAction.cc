--- src/PostgresAction.cc.orig	2017-05-07 11:16:01 UTC
+++ src/PostgresAction.cc
@@ -222,7 +222,7 @@ void PostgresAction::readChain()
 
 void PostgresAction::backChar() 
 {
-    if ( _pC > 0 )
+    if ( _pC != 0 )
 	_pC--;
 }
     
