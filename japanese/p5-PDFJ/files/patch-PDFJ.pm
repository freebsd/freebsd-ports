--- PDFJ.pm.orig	Mon Nov  3 17:20:56 2003
+++ PDFJ.pm	Mon Nov  3 17:55:17 2003
@@ -1801,9 +1801,9 @@
 	}
 	my $self;
 	if( @args == 1 ) {
-		if( !ref($args[0]) ) {
+		if( $args[0] and !ref($args[0]) ) {
 			$self = PDFJ::Util::strstyle2hashref($args[0]);
-		} elsif( ref($args[0]) eq 'HASH' || ref($args[0]) eq $class ) {
+		} elsif( $args[0] and (ref($args[0]) eq 'HASH' || ref($args[0]) eq $class) ) {
 			%$self = %{$args[0]};
 		} else {
 			croak "illegal $class->new() argument";
@@ -1811,7 +1811,7 @@
 	} else {
 		%$self = @args;
 	}
-	if( %$self == 1 && $self->{style} ) {
+	if( keys %$self == 1 && $self->{style} ) {
 		$self = $class->new($self->{style});
 	}
 	for my $key(keys %$self) {
@@ -1843,7 +1843,7 @@
 		} else {
 			%args = @args;
 		}
-		if( %args == 1 && $args{style} ) {
+		if( keys %args == 1 && $args{style} ) {
 			$clone = $self->clone($args{style});
 		} else {
 			$clone = $self->new(%$self);
@@ -3234,7 +3234,7 @@
 	my($self, $str) = @_;
 	my $style = $self->style;
 	my $result = [];
-	my @c = split('', $str);
+	my @c = split('', $str || "");
 	for( my $j = 0; $j <= $#c; $j++ ) {
 		my $c = $c[$j];
 		if( $c ge "\x81" && $c le "\x9f" || $c ge "\xe0" && $c le "\xfc" ) {
@@ -4166,7 +4166,6 @@
 sub new1 {
 	my($class, $value)
 		= PDFJ::Util::methodargs([qw(value)], @_);
-	my $class = shift;
 	my $self;
 	if( ref($value) eq 'ARRAY' ) {
 		$self = bless { type => 'rgb', value => $value }, $class;
@@ -4487,7 +4486,7 @@
 	my($self, $x, $y, $w, $h, $style)
 		= PDFJ::Util::methodargs([qw(x y w h style)], @_);
 	$style = PDFJ::ShapeStyle->new($style)
-		if !ref($style) || ref($style) eq 'HASH';
+		if ($style and (!ref($style) || ref($style) eq 'HASH'));
 	my @stylepdf;
 	@stylepdf = $style->pdf if $style;
 	my($x1, $y1, $x2, $y2) = ($x, $y, $x + $w, $y + $h);
@@ -4528,7 +4527,7 @@
 		= PDFJ::Util::methodargs([qw(x y w h spec style)], @_);
 	$spec = "s" unless $spec;
 	$style = PDFJ::ShapeStyle->new($style)
-		if !ref($style) || ref($style) eq 'HASH';
+		if ($style and (!ref($style) || ref($style) eq 'HASH'));
 	my @stylepdf;
 	@stylepdf = $style->pdf if $style;
 	my($r);
