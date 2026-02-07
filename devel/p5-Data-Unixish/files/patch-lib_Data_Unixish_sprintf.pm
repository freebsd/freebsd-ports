--- lib/Data/Unixish/sprintf.pm.orig	2019-10-26 02:14:22 UTC
+++ lib/Data/Unixish/sprintf.pm
@@ -3,7 +3,7 @@ package Data::Unixish::sprintf;
 use 5.010;
 use locale;
 use strict;
-use syntax 'each_on_array'; # to support perl < 5.12
+#use syntax 'each_on_array'; # to support perl < 5.12
 use warnings;
 #use Log::Any '$log';
 
