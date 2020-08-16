--- lib/Data/Unixish/num.pm.orig	2019-10-26 02:14:22 UTC
+++ lib/Data/Unixish/num.pm
@@ -6,7 +6,7 @@ our $VERSION = '1.572'; # VERSION
 use 5.010;
 use locale;
 use strict;
-use syntax 'each_on_array'; # to support perl < 5.12
+#use syntax 'each_on_array'; # to support perl < 5.12
 use warnings;
 #use Log::Any '$log';
 
