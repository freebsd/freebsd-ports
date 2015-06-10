--- F77.pm.orig	2015-06-07 20:28:59 UTC
+++ F77.pm
@@ -343,9 +343,49 @@ $F77config{Aix}{DEFAULT}     = 'F77';
 
 ### FreeBSD ###
 
-$F77config{Freebsd}{F77}{Trail_} = 1;
-$F77config{Freebsd}{F77}{Link}   = '-L/usr/lib -lf2c -lm';
-$F77config{Freebsd}{DEFAULT}     = 'F77';
+if($^O =~ /Freebsd/i) {
+  $gfortran = 'gfortran44'; # requires rewrite
+  $fallback_compiler = 'G77';
+}
+
+$F77config{Freebsd}{G77}{Link} = sub {
+    $dir = `g77-34 -print-file-name=libg2c.a`;
+    chomp $dir;
+    # Note that -print-file-name returns just the library name
+    # if it cant be found - make sure that we only accept the
+    # directory if it returns a proper path (or matches a /)
+
+    if( defined $dir ) {
+        $dir =~ s,/libg2c.a$,,;
+    } else {
+        $dir = "/usr/local/lib";
+    }    
+    return( "-L$dir -L/usr/lib -lg2c -lm" );
+};
+
+$F77config{Freebsd}{GFortran}{Link} = sub {
+    $dir = `$gfortran -print-file-name=libgfortran.a`;
+    chomp $dir;
+    # Note that -print-file-name returns just the library name
+    # if it cant be found - make sure that we only accept the
+    # directory if it returns a proper path (or matches a /)
+
+    if( defined $dir ) {
+        $dir =~ s,/libgfortran.a$,,;
+    } else {
+        $dir = "/usr/local/lib";
+    }    
+    return( "-L$dir -L/usr/lib -lgfortran -lm" );
+};
+
+$F77config{Freebsd}{G77}{Trail_} = 1;
+$F77config{Freebsd}{GFortran}{Trail_} = 1;
+$F77config{Freebsd}{G77}{Compiler} = 'g77-34';
+$F77config{Freebsd}{GFortran}{Compiler} = "$gfortran";
+$F77config{Freebsd}{G77}{Cflags} = '-O2';
+$F77config{Freebsd}{GFortran}{Cflags}   = '-O2';
+$F77config{Freebsd}{DEFAULT}     = 'GFortran';
+
 
 ### VMS ###
 
@@ -438,7 +478,8 @@ $Pkg: Will try system=Generic Compiler=$
 EOD
     	 $system   =
             $Config{cc} =~ /\bgcc/ && $^O =~ /MSWin32/i ? "MinGW"
-                                                        :"Generic";
+                                    : $^O =~ /Freebsd/i ? "Freebsd"
+                                                        : "Generic";
     	 $compiler = $fallback_compiler;
     	 my $flibs = get ($F77config{$system}{$compiler}{Link});
     	 $Runtime =  $flibs ; #. gcclibs($flibs); #  Note gcclibs appears to be no longer required.
