--- PDFJ.pm.orig	Sun Oct 22 19:27:42 2006
+++ PDFJ.pm	Fri Mar 30 15:15:27 2007
@@ -1093,7 +1093,7 @@
 		return;
 	}
 	push @filters, @addfilters if @addfilters;
-	my $filter = @filters > 1 ? [map {PDFJ::Object::name($_)} @filters] : 
+	$filter = @filters > 1 ? [map {PDFJ::Object::name($_)} @filters] : 
 		PDFJ::Object::name($filters[0]);
 	($encoded, $filter);
 }
@@ -1537,7 +1537,7 @@
 	unless( $self->{outlinetree} ) {
 		$self->{outlinetree} = [];
 	}
-	my $parent = $self->{outlinetree};
+	$parent = $self->{outlinetree};
 	for( my $j = 0; $j < $level; $j++ ) {
 		push @$parent, ['', undef, undef, undef, []] unless @$parent;
 		$parent = $$parent[$#$parent][4];
@@ -4036,6 +4036,7 @@
 		$font->{subset_unicodes}{$unicode} = 1 if $unicode;
 	}
 	if( @$chunks ) {
+		no warnings 'deprecated';
 		my $lastchunk = $chunks->[$#$chunks];
 		my $lastmode = $lastchunk->{Mode};
 		my $lastclass = $lastchunk->{Class};
@@ -4132,7 +4133,7 @@
 	my($self, $str, $noshift) = @_;
 	my $style = $self->style;
 	my $result = [];
-	my @c = split('', $str);
+	my @c = split('', $str || "");
 	for( my $j = 0; $j <= $#c; $j++ ) {
 		my $c = $c[$j];
 		next if $c eq "\x00";
