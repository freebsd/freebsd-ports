--- t/16xml-parser.t.orig	Sun May  9 19:15:25 2004
+++ t/16xml-parser.t	Sun May  9 19:27:08 2004
@@ -12,7 +12,7 @@
 
 use strict;
 use Test::More;
-use Test::Exception;
+#use Test::Exception;  # not actually used
 
 use strict;
 use Data::Dumper;
@@ -49,16 +49,16 @@
         if ( exists $test->{$attr} ) {
             my $ans = $test->{$attr};
             if ( $attr =~ m/^is_/ ) {
-                if ($ans) { ok $fld->$attr,  "$name - $attr true"; }
-                else      { ok !$fld->$attr, "$name - $attr false"; }
+                if ($ans) { ok $fld->$attr(),  "$name - $attr true"; }
+                else      { ok !$fld->$attr(), "$name - $attr false"; }
             }
             else {
-                is $fld->$attr, $ans, "$name - $attr = '"
+                is $fld->$attr(), $ans, "$name - $attr = '"
                                      .(defined $ans ? $ans : "NULL" )."'";
             }
         }
         else {
-            ok !$fld->$attr, "$name - $attr not set";
+            ok !$fld->$attr(), "$name - $attr not set";
         }
     }
 }
