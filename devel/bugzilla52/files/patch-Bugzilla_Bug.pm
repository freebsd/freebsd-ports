--- Bugzilla/Bug.pm.orig	2026-06-24 03:32:13 UTC
+++ Bugzilla/Bug.pm
@@ -587,7 +587,7 @@ sub possible_duplicates {
   my $products   = $params->{products} || [];
   my $limit      = $params->{limit} || MAX_POSSIBLE_DUPLICATES;
   $limit    = MAX_POSSIBLE_DUPLICATES if $limit > MAX_POSSIBLE_DUPLICATES;
-  $products = [$products]             if !ref($products) eq 'ARRAY';
+  $products = [$products]             if ref($products) neq 'ARRAY';
 
   my $orig_limit = $limit;
   detaint_natural($limit)
