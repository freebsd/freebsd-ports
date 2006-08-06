--- ./inc/Module/Install.pm.orig	Sat Aug  5 15:05:20 2006
+++ ./inc/Module/Install.pm	Sat Aug  5 15:05:52 2006
@@ -116,7 +116,7 @@
     my %seen;
     foreach my $obj ( @exts ) {
         while (my ($method, $glob) = each %{ref($obj) . '::'}) {
-            next unless exists &{ref($obj).'::'.$method};
+            next unless $obj->can($method);
             next if $method =~ /^_/;
             next if $method eq uc($method);
             $seen{$method}++;
