--- PDFJ/Matrix.pm.orig	2010-01-08 14:10:39.047483295 +0900
+++ PDFJ/Matrix.pm	2010-01-08 14:10:56.023648977 +0900
@@ -51,7 +51,7 @@
 	$self->{postnobreak} = [];
 	my $matrix = $self->{objects};
 	my $trimed;
-	my $maxrows;
+	my $maxrows = 0;
 	for( my $j = 0; $j < @$matrix; $j++ ) {
 		my $row = $matrix->[$j];
 		my $trow = [];
@@ -110,7 +110,7 @@
 	if( @$widths > 1 ) {
 		my $skip = $self->{direction} =~ /V$/ ? 
 			$self->{style}{colskip} : $self->{style}{rowskip};
-		$self->{width} += $skip * (@$widths - 1) 
+		$self->{width} += ($skip || 0) * (@$widths - 1) 
 	}
 }
 
@@ -122,7 +122,7 @@
 	if( @$heights > 1 ) {
 		my $skip = $self->{direction} =~ /^V/ ? 
 			$self->{style}{colskip} : $self->{style}{rowskip};
-		$self->{height} += $skip * (@$heights - 1) 
+		$self->{height} += ($skip || 0) * (@$heights - 1) 
 	}
 }
 
@@ -192,7 +192,7 @@
 		$self->_heights2height;
 	}
 	if( $adjust ) {
-		my $skip = $self->{style}{colskip};
+		my $skip = $self->{style}{colskip} || 0;
 		for( my $j = 0; $j < @$matrix; $j++ ) {
 			my $row = $matrix->[$j];
 			for( my $k = 0; $k < @$row; $k++ ) {
@@ -315,8 +315,8 @@
 sub _show {
 	my($self, $page, $x, $y) = @_;
 	my $direction = $self->{direction};
-	my $colskip = $self->{style}{colskip};
-	my $rowskip = $self->{style}{rowskip};
+	my $colskip = $self->{style}{colskip} || 0;
+	my $rowskip = $self->{style}{rowskip} || 0;
 	$self->_showbox($page, $x, $y);
 	$x += $self->padding + $self->{xpreshift};
 	$y -= $self->padding + $self->{ypreshift};
