--- inc/Module/Install.pm.orig	2006-01-16 15:53:58 UTC
+++ inc/Module/Install.pm
@@ -81,7 +81,7 @@ sub preload {
     my %seen_method;
     foreach my $obj (@exts) {
         while (my ($method, $glob) = each %{ref($obj) . '::'}) {
-            next unless defined *{$glob}{CODE};
+            next unless exists &{ref($obj).'::'.$method};
             next if $method =~ /^_/;
             next if $method eq uc($method);
             $seen_method{$method}++;
