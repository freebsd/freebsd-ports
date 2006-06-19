--- Makefile.PL.orig	Sat Apr  9 11:02:35 2005
+++ Makefile.PL	Mon Jun 19 13:33:18 2006
@@ -26,7 +26,7 @@
 
 configure();
 
-configPwd();
+#configPwd();
 
 my $lddlflags = $Config{lddlflags};
 $lddlflags = "-L$SYBASE/lib $lddlflags" unless $^O eq 'VMS';
@@ -151,16 +151,16 @@
 
 	my $extra = getExtraLibs($SYBASE, $attr{EXTRA_LIBS}, $version);
 	if($file) {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl -lblk $attr{EXTRA_LIBS} -ldl -lm";
+	    $lib_string = "-L$SYBASE/lib -lct -lintl $attr{EXTRA_LIBS} -lm";
 	} else {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl -lblk $extra -ldl -lm";
+	    $lib_string = "-L$SYBASE/lib -lct -lintl $extra -lm";
 	}
 	if($newlibnames) {
 	    foreach (qw(ct cs tcl comn intl blk)) {
 		$lib_string =~ s/-l$_/-lsyb$_/;
 	    }
-	} elsif($^O =~ /linux|freebsd/i) {
-	    $lib_string =~ s/-ltcl/-lsybtcl/;
 	}
+#	} elsif($^O =~ /linux|freebsd/i) {
+#	    $lib_string =~ s/-ltcl/-lsybtcl/;
  	}
 
 	# Logic to replace normal libs with _r (re-entrant) libs if
