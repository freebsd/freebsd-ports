--- ./Makefile.PL.orig	2009-07-14 19:34:21.530175414 -0400
+++ ./Makefile.PL	2009-07-14 19:35:55.039877625 -0400
@@ -192,8 +192,8 @@
 	    $defs .= " -DTCL_LIB_FILE=\\\"tcl$tclver.dll\\\"" if $usestubs; 
 	}
 	elsif ($^O eq 'freebsd') {
+        $tclcfg{tcl_library} =~ /^(.*)[\\\/]lib[\\\/]/ and $incpath .= " -I$1/include/tcl$tclver";
 	    $tclver=~s/\.//;
-	    $tclsh=~/([\d.]+)$/ and $incpath .= " -I/usr/local/include/tcl$1";
 	    $defs .= " -DTCL_LIB_FILE=\\\"libtcl$tclver.so\\\"" if $usestubs; 
 	}
 	elsif ($^O eq 'hpux') {
