Obtained from: https://rt.cpan.org/Public/Bug/Display.html?id=70701
--- test.pl.orig	2005-12-30 19:36:54.000000000 -0900
+++ test.pl	2012-04-04 06:13:52.000000000 -0800
@@ -103,6 +103,7 @@
 
 if ($t4) {
     $t4 = POE::Component::Child->new(
+        writemap => { quit => "bye" },
     	events => \%t4, debug => $debug
     	);
     ok(defined $t4 && $t4->isa('POE::Component::Child'), "[4] init - pipe close");
