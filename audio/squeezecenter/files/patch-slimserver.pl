
$FreeBSD$

--- slimserver.pl.orig
+++ slimserver.pl
@@ -193,6 +193,7 @@
 		catdir($Bin,'CPAN','arch',$Config::Config{'archname'}),
 		catdir($Bin,'lib'), 
 		catdir($Bin,'CPAN'), 
+		catdir($Bin,''), 
 	);
 
 	$d_startup && printf("Got \@INC containing:\n%s\n\n", join("\n", @INC));
