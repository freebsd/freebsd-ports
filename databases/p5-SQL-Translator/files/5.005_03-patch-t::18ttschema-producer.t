--- t/18ttschema-producer.t.orig	Sun May  9 20:56:35 2004
+++ t/18ttschema-producer.t	Sun May  9 20:57:54 2004
@@ -6,7 +6,10 @@
 
 use strict;
 use Test::More;
-use Test::Exception;
+use vars '$no_test_exception';
+$no_test_exception = 0;
+eval { require Test::Exception; };
+$no_test_exception = $@;
 
 use Data::Dumper;
 use vars '%opt';
@@ -47,7 +50,12 @@
     },
 );
 my $out;
-lives_ok { $out = $obj->translate; }  "Translate ran";
+if ($no_test_exception) {
+    $out = $obj->translate;
+    pass "Translate ran";
+} else {
+    lives_ok { $out = $obj->translate; }  "Translate ran";
+}
 ok $out ne ""                        ,"Produced something!";
 local $/ = undef; # slurp
 eq_or_diff $out, <DATA>              ,"Output looks right";
