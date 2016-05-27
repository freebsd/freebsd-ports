--- cpan/Math-BigInt/lib/Math/BigInt.pm.orig	2016-01-06 13:21:01 UTC
+++ cpan/Math-BigInt/lib/Math/BigInt.pm
@@ -65,7 +65,7 @@ use overload
 '>>='   =>      sub { $_[0]->brsft($_[1]); },
 
 # not supported by Perl yet
-'..'    =>      \&_pointpoint,
+# '..'    =>      \&_pointpoint,
 
 '<=>'   =>      sub { my $rc = $_[2] ?
                       ref($_[0])->bcmp($_[1],$_[0]) :
