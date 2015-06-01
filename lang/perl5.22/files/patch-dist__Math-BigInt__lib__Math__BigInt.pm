--- dist/Math-BigInt/lib/Math/BigInt.pm.orig	2015-04-15 07:47:18 UTC
+++ dist/Math-BigInt/lib/Math/BigInt.pm
@@ -62,7 +62,7 @@ use overload
 '>>='	=>	sub { $_[0]->brsft($_[1]); },
 
 # not supported by Perl yet
-'..'	=>	\&_pointpoint,
+# '..'	=>	\&_pointpoint,
 
 '<=>'	=>	sub { my $rc = $_[2] ?
                       ref($_[0])->bcmp($_[1],$_[0]) : 
