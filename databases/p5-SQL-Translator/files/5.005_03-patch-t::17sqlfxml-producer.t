--- t/17sqlfxml-producer.t.orig	Sun May  9 20:51:50 2004
+++ t/17sqlfxml-producer.t	Sun May  9 20:55:44 2004
@@ -8,7 +8,10 @@
 
 use strict;
 use Test::More;
-use Test::Exception;
+use vars '$no_test_exception';
+$no_test_exception = 0;
+eval { require Test::Exception; };
+$no_test_exception = $@;
 
 use Data::Dumper;
 my %opt;
@@ -149,7 +152,12 @@
     from           => 'MySQL',
     to             => 'XML-SQLFairy',
 );
-lives_ok {$xml = $obj->translate($file);} "Translate (emit_empty_tags=>0) ran";
+if ($no_test_exception) {
+    $xml = $obj->translate($file);
+    pass "Translate (emit_empty_tags=>0) ran";
+} else {
+    lives_ok {$xml = $obj->translate($file);} "Translate (emit_empty_tags=>0) ran";
+}
 ok("$xml" ne ""                             ,"Produced something!");
 print "XML:\n$xml" if DEBUG;
 # Strip sqlf header with its variable date so we diff safely
@@ -270,7 +278,12 @@
     to             => 'XML-SQLFairy',
     producer_args  => { emit_empty_tags => 1 },
 );
-lives_ok { $xml=$obj->translate($file); } "Translate (emit_empty_tags=>1) ran";
+if ($no_test_exception) {
+    $xml=$obj->translate($file);
+    pass "Translate (emit_empty_tags=>1) ran";
+} else {
+    lives_ok { $xml=$obj->translate($file); } "Translate (emit_empty_tags=>1) ran";
+}
 ok("$xml" ne ""                             ,"Produced something!");
 print "XML emit_empty_tags=>1:\n$xml" if DEBUG;
 # Strip sqlf header with its variable date so we diff safely
@@ -314,7 +327,12 @@
     to             => "XML-SQLFairy",
     producer_args  => { attrib_values => 1 },
 );
-lives_ok {$xml = $obj->translate($file);} "Translate (attrib_values=>1) ran";
+if ($no_test_exception) {
+    $xml = $obj->translate($file);
+    pass "Translate (attrib_values=>1) ran";
+} else {
+    lives_ok {$xml = $obj->translate($file);} "Translate (attrib_values=>1) ran";
+}
 ok("$xml" ne ""                             ,"Produced something!");
 print "XML attrib_values=>1:\n$xml" if DEBUG;
 # Strip sqlf header with its variable date so we diff safely
@@ -364,7 +382,12 @@
     
     # As we have created a Schema we give translate a dummy string so that
     # it will run the produce.
-    lives_ok {$xml =$obj->translate("FOO");} "Translate (View) ran";
+    if ($no_test_exception) {
+        $xml =$obj->translate("FOO");
+        pass "Translate (View) ran";
+    } else {
+        lives_ok {$xml =$obj->translate("FOO");} "Translate (View) ran";
+    }
     ok("$xml" ne ""                             ,"Produced something!");
     print "XML attrib_values=>1:\n$xml" if DEBUG;
     # Strip sqlf header with its variable date so we diff safely
@@ -418,7 +441,12 @@
     
     # As we have created a Schema we give translate a dummy string so that
     # it will run the produce.
-    lives_ok {$xml =$obj->translate("FOO");} "Translate (Trigger) ran";
+    if ($no_test_exception) {
+        $xml =$obj->translate("FOO");
+        pass "Translate (Trigger) ran";
+    } else {
+        lives_ok {$xml =$obj->translate("FOO");} "Translate (Trigger) ran";
+    }
     ok("$xml" ne ""                             ,"Produced something!");
     print "XML attrib_values=>1:\n$xml" if DEBUG;
     # Strip sqlf header with its variable date so we diff safely
@@ -472,7 +500,12 @@
 
     # As we have created a Schema we give translate a dummy string so that
     # it will run the produce.
-    lives_ok {$xml =$obj->translate("FOO");} "Translate (Procedure) ran";
+    if ($no_test_exception) {
+        $xml =$obj->translate("FOO");
+        pass "Translate (Procedure) ran";
+    } else {
+        lives_ok {$xml =$obj->translate("FOO");} "Translate (Procedure) ran";
+    }
     ok("$xml" ne ""                             ,"Produced something!");
     print "XML attrib_values=>1:\n$xml" if DEBUG;
     # Strip sqlf header with its variable date so we diff safely
