--- PDFJ/PNG.pm.orig	2010-01-08 14:10:44.679341560 +0900
+++ PDFJ/PNG.pm	2010-01-08 14:11:00.479580442 +0900
@@ -177,8 +177,8 @@
 			}, stream => $encoded));
 	} elsif( $colorspace == 6 ) { # RGB+alpha
 		croak "PNG over 8 bit RGB+alpha not supported" if $bpc > 8;
-		my $mdata;
-		my $maskdata;
+		my $mdata = '';
+		my $maskdata = '';
 		my $scanline = ceil($bpc * 4 * $width / 8) + 1;
 		my $bpp = ceil($bpc * 4 / 8);
 		my $clearstream = 
