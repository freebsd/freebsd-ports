Index: main/Configuration/Block.pm
diff -u main/Configuration/Block.pm.orig main/Configuration/Block.pm
--- main/Configuration/Block.pm.orig	2010-02-12 03:34:30.000000000 +0900
+++ main/Configuration/Block.pm	2015-09-01 16:49:33.521015928 +0900
@@ -140,7 +140,7 @@
 	}
 	$result;
     };
-    (my $evaluated = $str) =~ s/\%CODE{(.*?)}EDOC\%/$eval->($1)/eg;
+    (my $evaluated = $str) =~ s/\%CODE\{(.*?)}EDOC\%/$eval->($1)/eg;
     $evaluated;
 }
 
