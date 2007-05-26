--- XPDFJ.pm.orig	Fri Mar 30 15:01:05 2007
+++ XPDFJ.pm	Fri Mar 30 15:01:17 2007
@@ -122,7 +122,7 @@
 sub _method_parse {
 	my($self, $tree, $this, $args, $mode) = @_;
 	my @result;
-	my $mmode = $mode;
+	my $mmode = $mode || "";
 	my $mlevel = 0;
 	if( $mmode =~ s/:(\d+)$// ) {
 		$mlevel = $1;
