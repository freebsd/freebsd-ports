--- PDFJ.pm.orig	2006-10-22 19:27:42.000000000 +0900
+++ PDFJ.pm	2010-01-08 14:10:29.259440247 +0900
@@ -21,6 +21,24 @@
 	bytes->import unless $@;
 }
 
+# use hash in place of phash for Perl 5.9 or later
+BEGIN {
+	my $body;
+	unless ($] > 5.008) {
+		$body = sub { [ @_ ] };
+	} else {
+		$body = sub {
+			my($pos) = @_;
+			my $hash;
+			foreach my $k (keys(%$pos)) {
+				$hash->{$k} = $_[$pos->{$k}];
+			}
+			return $hash;
+		};
+	}
+	eval { sub _hash { $body->(@_) } };
+}
+
 @EXFUNC = qw(
 	PDFJ::Doc::Doc
 	PDFJ::TextStyle::TStyle PDFJ::Text::Text 
@@ -1093,7 +1111,7 @@
 		return;
 	}
 	push @filters, @addfilters if @addfilters;
-	my $filter = @filters > 1 ? [map {PDFJ::Object::name($_)} @filters] : 
+	$filter = @filters > 1 ? [map {PDFJ::Object::name($_)} @filters] : 
 		PDFJ::Object::name($filters[0]);
 	($encoded, $filter);
 }
@@ -1537,7 +1555,7 @@
 	unless( $self->{outlinetree} ) {
 		$self->{outlinetree} = [];
 	}
-	my $parent = $self->{outlinetree};
+	$parent = $self->{outlinetree};
 	for( my $j = 0; $j < $level; $j++ ) {
 		push @$parent, ['', undef, undef, undef, []] unless @$parent;
 		$parent = $$parent[$#$parent][4];
@@ -2720,7 +2738,7 @@
 	my $render = $self->{render} || 0;
 	my @shapepdf = $self->{shapestyle} ? $self->{shapestyle}->pdf : ();
 	my $contentmark = $self->{contentmark};
-	my @pdf = $contentmark ne '' ? ("/$contentmark BMC q") : ("q");
+	my @pdf = ($contentmark || "") ne '' ? ("/$contentmark BMC q") : ("q");
 	push @pdf, @shapepdf if @shapepdf;
 	push @pdf, "BT /$fontname", number($fontsize), "Tf", number($rise), "Ts $render Tr";
 	@pdf;
@@ -2728,7 +2746,7 @@
 
 sub endpdf {
 	my($self) = @_;
-	$self->{contentmark} ne '' ? "] TJ ET Q EMC " : "] TJ ET Q ";
+	($self->{contentmark} || "") ne '' ? "] TJ ET Q EMC " : "] TJ ET Q ";
 }
 
 #--------------------------------------------------------------------------
@@ -2874,6 +2892,7 @@
 	my($self, $indent) = @_;
 	my $style = $self->style;
 	return unless $style->{font};
+	$indent = '' if (not defined $indent);
 	for my $text(@{$self->texts}) {
 		if( PDFJ::Util::objisa($text, 'PDFJ::Text') ) {
 			$text->style->merge($style);
@@ -3201,8 +3220,8 @@
 			$preskip = $lineskip;
 		}
 		push @lines, 
-			[\%TextLineIndex, $start, $count, $shift, $fixedglues, $preaols, 
-			$postaols, $preskip];
+			PDFJ::_hash(\%TextLineIndex, $start, $count, $shift, $fixedglues,
+				$preaols, $postaols, $preskip);
 		$start = $nextpos;
 	}
 	@lines;
@@ -4036,6 +4055,7 @@
 		$font->{subset_unicodes}{$unicode} = 1 if $unicode;
 	}
 	if( @$chunks ) {
+		no warnings 'deprecated';
 		my $lastchunk = $chunks->[$#$chunks];
 		my $lastmode = $lastchunk->{Mode};
 		my $lastclass = $lastchunk->{Class};
@@ -4132,7 +4152,7 @@
 	my($self, $str, $noshift) = @_;
 	my $style = $self->style;
 	my $result = [];
-	my @c = split('', $str);
+	my @c = split('', $str || "");
 	for( my $j = 0; $j <= $#c; $j++ ) {
 		my $c = $c[$j];
 		next if $c eq "\x00";
@@ -4322,8 +4342,7 @@
 
 sub new {
 	my($class, @args) = @_;
-	unshift @args, \%ChunkIndex;
-	bless \@args, $class;
+	bless PDFJ::_hash(\%ChunkIndex, @args), $class;
 }
 
 sub clone {
@@ -4371,7 +4390,7 @@
 	croak "linefeed specification missing" unless exists $style->{linefeed};
 	croak "align specification missing" unless $style->{align};
 	my $self = bless { text => $text, style => $style }, $class;
-	$self->typename($style->{typename}) if $style->{typename} ne '';
+	$self->typename($style->{typename}) if ($style->{typename});
 	$self->{linefeed} = $style->{linefeed};
 	if( $self->{linefeed} =~ s/s(\d+%?)// ) {
 		$self->{lineskipmin} = $1;
@@ -4817,7 +4836,7 @@
 	my $self = bless { direction => $direction, objects => \@objects, 
 		xpreshift => 0, xpostshift => 0, ypreshift => 0, ypostshift => 0, 
 		style => $style }, $dclass;
-	$self->typename($style->{typename}) if $style->{typename} ne '';
+	$self->typename($style->{typename}) if ($style->{typename});
 	$self->_checkobjects;
 	$self->_calcsize;
 	$self->adjustwidth($style->{width}) if $style->{width};
@@ -5136,10 +5155,10 @@
 			carp "break fails";
 			return;
 		}
-		if( @bobjects && $bobjects[0]->{floatsep} eq 'b' ) {
+		if( @bobjects && ($bobjects[0]->{floatsep} || "") eq 'b' ) {
 			shift @bobjects;
 		}
-		if( @bobjects && $bobjects[$#bobjects]->{floatsep} eq 'e' ) {
+		if( @bobjects && ($bobjects[$#bobjects]->{floatsep} || '') eq 'e' ) {
 			pop @bobjects;
 		}
 		if( $repeatheader && (@bobjects >= $repeatheader) && @objects ) {
@@ -5188,7 +5207,7 @@
 	} elsif( $float eq '' || $float eq 'h' ) {
 		$inspos = @$objects;
 		while( $inspos > 0 && ($objects->[$inspos - 1]->float =~ /e/ ||
-			$objects->[$inspos - 1]->{floatsep} =~ /e/)) {
+			($objects->[$inspos - 1]->{floatsep} || "") =~ /e/)) {
 			$inspos--;
 		}
 	} else {
@@ -5210,7 +5229,7 @@
 				$height += skipsize($self->{objects}->[$j-1], $obj);
 			}
 			if( PDFJ::Util::objisa($obj, 'PDFJ::Showable') ) {
-				my $owidth = $obj->width + $obj->blockalign;
+				my $owidth = $obj->width + ($obj->blockalign || 0);
 				$width = $width < $owidth ? $owidth : $width;
 				$height += $obj->height;
 			} elsif( PDFJ::Util::objisa($obj, 'PDFJ::BlockElement') ) {
@@ -5229,7 +5248,7 @@
 		for( my $j = 0; $j < $objnum; $j++ ) {
 			my $obj = $self->{objects}->[$j];
 			if( PDFJ::Util::objisa($obj, 'PDFJ::Showable') ) {
-				my $aib = $obj->blockalign;
+				my $aib = $obj->blockalign || '';
 				if( $aib eq '' ) {
 					$indents[$j] = ($width - $obj->width) * $indentratio;
 				} elsif( $aib eq 'b' ) {
@@ -6635,8 +6654,8 @@
 	if( $lastobjnum ) {
 		for my $objnum(1 .. $lastobjnum) {
 			printf $handle "%010.10d %05.5d n \n", 
-				$self->{objposlist}->[$objnum], 
-				$objtable->get($objnum)->{gennum};
+				$self->{objposlist}->[$objnum] || 0, 
+				$objtable->get($objnum)->{gennum} || 0;
 		}
 	}
 	print $handle "\n";
