--- lib/Data/Unixish/count.pm.orig	2019-10-26 02:14:22 UTC
+++ lib/Data/Unixish/count.pm
@@ -7,7 +7,7 @@ our $VERSION = '1.572'; # VERSION
 use 5.010001;
 use locale;
 use strict;
-use syntax 'each_on_array'; # to support perl < 5.12
+#use syntax 'each_on_array'; # to support perl < 5.12
 use warnings;
 use Log::ger;
 
