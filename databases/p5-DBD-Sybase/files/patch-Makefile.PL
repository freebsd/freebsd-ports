--- Makefile.PL.orig	Thu May 10 17:56:44 2001
+++ Makefile.PL	Thu May 10 17:58:36 2001
@@ -107,13 +107,13 @@
     } else {
 	my $extra = getExtraLibs($SYBASE, $attr{EXTRA_LIBS});
 	if($file) {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl $attr{EXTRA_LIBS} -lm";
+	    $lib_string = "-L$SYBASE/lib -lct -lintl $attr{EXTRA_LIBS} -lm";
 	} else {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl $extra -lm";
-	}
-	if($^O =~ /linux|freebsd/i) {
-	    $lib_string =~ s/ltcl/lsybtcl/;
+	    $lib_string = "-L$SYBASE/lib -lct -lintl $extra -lm";
 	}
+#	if($^O =~ /linux|freebsd/i) {
+#	    $lib_string =~ s/ltcl/lsybtcl/;
+#	}
     }
     
     my $config_sitearch = $Config{sitearchexp};
