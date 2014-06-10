--- dist/Math-BigInt/lib/Math/BigInt.pm-orig	2014-06-09 16:22:23.000000000 +0200
+++ dist/Math-BigInt/lib/Math/BigInt.pm	2014-06-09 16:22:54.000000000 +0200
@@ -62,7 +62,7 @@
 '>>='	=>	sub { $_[0]->brsft($_[1]); },
 
 # not supported by Perl yet
-'..'	=>	\&_pointpoint,
+# '..'	=>	\&_pointpoint,
 
 '<=>'	=>	sub { my $rc = $_[2] ?
                       ref($_[0])->bcmp($_[1],$_[0]) : 
