--- SurePay.pm.orig	Sat Apr 12 10:25:20 2003
+++ SurePay.pm	Sat Apr 12 10:25:35 2003
@@ -152,7 +152,7 @@
 
 use strict;
 
-our (%_Valid_Type,%_Valid_Field);
+use vars qw(%_Valid_Type %_Valid_Field);
 foreach (qw( billing shipping )) {
   $_Valid_Type{$_}++;
 }
