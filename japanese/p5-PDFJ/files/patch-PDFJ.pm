--- PDFJ.pm.orig	Fri Oct 18 14:18:10 2002
+++ PDFJ.pm	Thu Oct 24 16:31:42 2002
@@ -813,7 +813,7 @@
 
 sub ascii85chunk {
 	my($chunk) = @_;
-	my $chunk = unpack("N", $chunk);
+	$chunk = unpack("N", $chunk);
 	my $resultchunk;
 	$resultchunk .= chr(int($chunk / (85 ** 4)) + 33);
 	$chunk = $chunk % (85 ** 4);
@@ -1394,9 +1394,9 @@
 	croak "ascii font type mismatch"
 		if $hfontobj && !UNIVERSAL::isa($hfontobj, "PDFJ::AFont");
 	my $name = $docobj->_fontname($basefont, $encoding);
-	my $hname = $hfontobj ? $hfontobj->{name} : undef;
-	return $docobj->_fontobj($name, $hname) 
-		if $name && $docobj->_fontobj($name, $hname);
+	my $hfontname = $hfontobj ? $hfontobj->{name} : undef;
+	return $docobj->_fontobj($name, $hfontname) 
+		if $name && $docobj->_fontobj($name, $hfontname);
 	# Zenkaku font
 	my $code = $PDFJ::Default{Jcode};
 	my($direction) = $encoding =~ /-(\w+)$/;
@@ -1460,9 +1460,9 @@
 	croak "ascii font type mismatch"
 		if $hfontobj && !UNIVERSAL::isa($hfontobj, "PDFJ::AFont");
 	my $name = $docobj->_fontname($ttffile, $encoding);
-	my $hname = $hfontobj ? $hfontobj->{name} : undef;
-	return $docobj->_fontobj($name, $hname) 
-		if $name && $docobj->_fontobj($name, $hname);
+	my $hfontname = $hfontobj ? $hfontobj->{name} : undef;
+	return $docobj->_fontobj($name, $hfontname) 
+		if $name && $docobj->_fontobj($name, $hfontname);
 	# Zenkaku font
 	my $code = $PDFJ::Default{Jcode};
 	my($direction) = $encoding =~ /-(\w+)$/;
@@ -1729,7 +1729,9 @@
 sub equal {
 	my($self, $other) = @_;
 	for my $key(qw(fontname fontsize render rise shapestyle)) {
-		return 0 if $self->{$key} ne $other->{$key};
+		return 0 if (($self->{$key} and not $other->{$key}) or
+			     (not $self->{$key} and $other->{$key}) or
+			     ($self->{$key} ne $other->{$key}));
 	}
 	return 1;
 }
@@ -1739,8 +1741,8 @@
 	croak "no fontsize specification" unless $self->{fontsize};
 	my $fontname = $self->{fontname};
 	my $fontsize = $self->{fontsize};
-	my $rise = $self->{rise} + 0;
-	my $render = $self->{render} + 0;
+	my $rise = $self->{rise} || 0;
+	my $render = $self->{render} || 0;
 	my $shapepdf = $self->{shapestyle} ? $self->{shapestyle}->pdf : "";
 	my $pdf = "q ";
 	$pdf .= "$shapepdf " if $shapepdf;
@@ -2336,7 +2338,7 @@
 				my $chunk = $self->chunk($start + $j);
 				if( $chunk->{Splittable} ) {
 					#$chunk->{GlueFix} += $incsize / $chunk->{Style}{fontsize} / 
-						$splittables;
+					#	$splittables;
 					$fixedglues[$j] += $incsize / $chunk->{Style}{fontsize} / 
 						$splittables;
 				}
@@ -2388,11 +2390,11 @@
 	my $docobj = $page->docobj;
 	my $chunksnum = $self->chunksnum;
 	my %usefontname;
-	my($tj, $dotpdf, $shapepdf);
+	my($tj, $dotpdf, $shapepdf) = ("", "", "");
 	my $lasttextspec = PDFJ::TextSpec->new;
-	my($lastfontname, $lastfontsize, $postshift, $ulx, $uly, $bxx, $bxy, 
-		$slant, $va, $lastfrx, $lastfry, $withlinestyle, $withbox, 
-		$withboxstyle);
+	my($lastfontsize, $postshift, $va, $ulx, $uly, $bxx, $bxy, 
+		$slant, $lastfrx, $lastfry, $withlinestyle, $withbox, 
+		$withboxstyle) = (0, 0, 0);
 	for( my $j = 0; $j < $count && $start + $j < $chunksnum; $j++ ) {
 		my $chunk = $self->chunk($start + $j);
 		my $mode = $chunk->{Mode};
@@ -2528,7 +2530,7 @@
 					$align = 'tc';
 				}
 			}
-			my $altsize = $altsize * 1000 / $fontsize;
+			$altsize = $altsize * 1000 / $fontsize;
 			$altsize = -$altsize if $direction eq 'H';
 			$tj .= "$altsize ";
 			$altobj->show($page, $flx + $asx, $fly + $asy, $align);
@@ -2782,7 +2784,7 @@
 sub _appendchunks {
 	my($chunks, $style, $mode, $class, $char, $preshift, $postshift, 
 		$nottol, $noteol) = @_;
-	my($splittable, $glue, $gluedec, $glueinc, $gluepref);
+	my($splittable, $glue, $gluedec, $glueinc, $gluepref) = (0, 0, 0, 0);
 	if( exists $style->{font} && exists $style->{font}{subset_unicodes} ) {
 		my $unicode = $PDFJ::Default{Jcode} eq 'SJIS' ? 
 			PDFJ::Unicode::s2u($char) : PDFJ::Unicode::e2u($char);
@@ -2810,6 +2812,8 @@
 		}
 		($glue, $gluedec, $glueinc, $gluepref) = _calcglue($glue);
 	}
+	$preshift =  0 if (not defined $preshift);
+	$postshift = 0 if (not defined $postshift);
 	push @$chunks, [\%ChunkIndex, $style, $mode, $class, $splittable, 
 		$glue, $gluedec, $glueinc, $gluepref, 1, $char, 
 		$preshift, $postshift];
@@ -2971,7 +2975,13 @@
 use vars qw(@ISA);
 @ISA = qw(PDFJ::Style);
 
-sub PStyle { PDFJ::ParagraphStyle->new(@_) }
+sub PStyle {
+  my $self = PDFJ::ParagraphStyle->new(@_);
+  foreach (qw(labelsize beginindent endindent)) {
+    $self->{$_} = 0 if (not defined $self->{$_});
+  }
+  $self;
+}
 
 #--------------------------------------------------------------------------
 package PDFJ::Paragraph;
@@ -3164,7 +3174,11 @@
 use vars qw(@ISA);
 @ISA = qw(PDFJ::Style);
 
-sub BStyle { PDFJ::BlockStyle->new(@_) }
+sub BStyle {
+  my $self = PDFJ::BlockStyle->new(@_);
+  $self->{align} = "tl" if (not defined $self->{align});
+  $self;
+}
 
 #--------------------------------------------------------------------------
 package PDFJ::Block;
@@ -3187,6 +3201,8 @@
 	my $objects = (@objects == 1 && ref($objects[0]) eq 'ARRAY') ? 
 		$objects[0] : \@objects;
 	my $self = bless { direction => $direction, objects => $objects, 
+			   xpreshift => 0, xpostshift => 0,
+			   ypreshift => 0, ypostshift => 0,
 		style => $style }, $class;
 	$self->_calcsize;
 	$self->adjustwidth($style->{width}) if $style->{width};
@@ -3278,7 +3294,7 @@
 
 sub _calcsize {
 	my($self) = @_;
-	my($width, $height);
+	my($width, $height) = (0, 0);
 	my $objnum = @{$self->{objects}};
 	my $adjust = $self->{style}{adjust};
 	my $align = $self->{style}{align};
@@ -3450,7 +3466,7 @@
 	if( $self->{direction} eq 'V' ) {
 		for( my $j = 0; $j < $objnum; $j++ ) {
 			my $obj = $self->{objects}->[$j];
-			my $indent = $self->{indents}->[$j];
+			my $indent = $self->{indents}->[$j] || 0;
 			if( $j > 0 ) {
 				my $preobj = $self->{objects}->[$j-1];
 				$y -= $preobj->postskip 
