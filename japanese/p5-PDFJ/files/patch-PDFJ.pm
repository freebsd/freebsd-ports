--- PDFJ.pm.orig	Thu Oct 28 18:02:55 2004
+++ PDFJ.pm	Fri Nov  5 14:59:35 2004
@@ -3750,7 +3750,7 @@
 	my($self, $str) = @_;
 	my $style = $self->style;
 	my $result = [];
-	my @c = split('', $str);
+	my @c = split('', $str || "");
 	for( my $j = 0; $j <= $#c; $j++ ) {
 		my $c = $c[$j];
 		if( $c ge "\x81" && $c le "\x9f" || $c ge "\xe0" && $c le "\xfc" ) {
