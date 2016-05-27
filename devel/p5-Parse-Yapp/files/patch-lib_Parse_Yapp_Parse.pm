--- lib/Parse/Yapp/Parse.pm.orig	2001-05-20 11:19:57 UTC
+++ lib/Parse/Yapp/Parse.pm
@@ -880,7 +880,7 @@ sub _Lexer {
         return($1, [ $1, $lineno[0] ]);
     };
 
-        $$input=~/\G{/gc
+        $$input=~/\G\{/gc
     and do {
         my($level,$from,$code);
 
@@ -907,7 +907,7 @@ sub _Lexer {
         and return('START',[ undef, $lineno[0] ]);
             $$input=~/\G%(expect)/gc
         and return('EXPECT',[ undef, $lineno[0] ]);
-            $$input=~/\G%{/gc
+            $$input=~/\G%\{/gc
         and do {
             my($code);
 
