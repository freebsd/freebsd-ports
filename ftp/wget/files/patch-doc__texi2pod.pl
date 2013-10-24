--- doc/texi2pod.pl.orig	2013-10-24 16:59:55.000000000 +0300
+++ doc/texi2pod.pl	2013-10-24 17:01:23.000000000 +0300
@@ -291,7 +291,7 @@
 	if (defined $1) {
             my $thing = $1;
             if ($ic =~ /\@asis/) {
-                $_ = "\n=item $thing\n";
+                $_ = "\n=item C<$thing>\n";
             } else {
                 # Entity escapes prevent munging by the <> processing below.
                 $_ = "\n=item $ic\&LT;$thing\&GT;\n";
