--- Makefile.PL.orig	2016-02-21 16:07:40 UTC
+++ Makefile.PL
@@ -168,8 +168,8 @@ if (defined($libpath) && defined($incpat
 	    $defs .= " -DTCL_LIB_FILE=\\\"tcl$tclver.dll\\\"" if $usestubs; 
 	}
 	elsif ($^O eq 'freebsd') {
+        $tclcfg{tcl_library} =~ /^(.*)[\\\/]lib[\\\/]/ and $incpath .= " -I$1/include/tcl$tclver";
 	    $tclver=~s/\.//;
-	    $tclsh=~/([\d.]+)$/ and $incpath .= " -I/usr/local/include/tcl$1";
 	    $defs .= " -DTCL_LIB_FILE=\\\"libtcl$tclver.so\\\"" if $usestubs; 
 	}
 	elsif ($^O eq 'hpux') {
