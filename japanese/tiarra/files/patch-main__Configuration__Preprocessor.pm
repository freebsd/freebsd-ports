Index: main/Configuration/Preprocessor.pm
diff -u main/Configuration/Preprocessor.pm.orig main/Configuration/Preprocessor.pm
--- main/Configuration/Preprocessor.pm.orig	2010-02-12 03:34:30.000000000 +0900
+++ main/Configuration/Preprocessor.pm	2015-09-01 16:49:03.358017196 +0900
@@ -165,7 +165,7 @@
 	}
 	defined $result ? $result : '';
     };
-    $body =~ s/\%PRE{(.+?)}ERP\%/$evaluate->($1)/seg;
+    $body =~ s/\%PRE\{(.+?)}ERP\%/$evaluate->($1)/seg;
     $body;
 }
 
