--- lib/Data/Unixish/sum.pm.orig	2019-10-26 02:14:22 UTC
+++ lib/Data/Unixish/sum.pm
@@ -2,7 +2,7 @@ package Data::Unixish::sum;
 
 use 5.010;
 use strict;
-use syntax 'each_on_array'; # to support perl < 5.12
+#use syntax 'each_on_array'; # to support perl < 5.12
 use warnings;
 #use Log::Any '$log';
 use Scalar::Util 'looks_like_number';
