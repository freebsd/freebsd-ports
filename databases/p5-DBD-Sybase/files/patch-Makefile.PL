--- Makefile.PL.orig	Mon Mar 31 18:55:11 2003
+++ Makefile.PL	Thu May 15 20:44:09 2003
@@ -22,7 +22,7 @@
 
 configure();
 
-configPwd();
+#configPwd();
 
 my $lddlflags = $Config{lddlflags};
 $lddlflags = "-L$SYBASE/lib $lddlflags" unless $^O eq 'VMS';
@@ -111,13 +111,13 @@
     } else {
 	my $extra = getExtraLibs($SYBASE, $attr{EXTRA_LIBS});
 	if($file) {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl $attr{EXTRA_LIBS} -ldl -lm";
+	    $lib_string = "-L$SYBASE/lib -lct -lintl $attr{EXTRA_LIBS} -lm";
 	} else {
-	    $lib_string = "-L$SYBASE/lib -lct -lcs -ltcl -lcomn -lintl $extra -ldl -lm";
-	}
-	if($^O =~ /linux|freebsd/i) {
-	    $lib_string =~ s/ltcl/lsybtcl/;
-	}
+           $lib_string = "-L$SYBASE/lib -lct -lintl $extra -lm";
+        }
+#       if($^O =~ /linux|freebsd/i) {
+#          $lib_string =~ s/ltcl/lsybtcl/;
+#       }
 	if($attr{BUILD_TYPE} == 64) {
 	    $inc_string .= ' -DSYB_LP64';
 	    print "Running in 64bit mode - looking for '64' libraries...\n";
