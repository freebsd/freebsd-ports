--- compiler/cfileutl.pas.orig	2015-11-13 21:15:29 UTC
+++ compiler/cfileutl.pas
@@ -23,9 +23,7 @@ unit cfileutl;
 
 {$i fpcdefs.inc}
 
-{$ifndef DragonFly}
 {$define usedircache}
-{$endif DragonFly}
 
 interface
 
