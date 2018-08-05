--- Makefile.PL.orig	2018-07-25 16:31:13 UTC
+++ Makefile.PL
@@ -191,8 +191,8 @@ if (defined($libpath) && defined($incpat
 	    $defs .= " -DTCL_LIB_FILE=\\\"tcl$tclver.$Config{so}\\\"" if $usestubs; 
 	}
 	elsif ($^O eq 'freebsd' or $^O eq 'openbsd' or $^O eq 'netbsd') {
+	    $tclcfg{tcl_library} =~ /^(.*)[\\\/]lib[\\\/]/ and $incpath .= " -I$1/include/tcl$tclver";
 	    $tclver=~s/\.//;
-	    $tclsh=~/([\d.]+)$/ and $incpath .= " -I/usr/local/include/tcl$1";
 	    $defs .= " -DTCL_LIB_FILE=\\\"libtcl$tclver.$Config{so}\\\"" if $usestubs; 
 	}
 	else {
