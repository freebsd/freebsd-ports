$FreeBSD$

--- lib/ExtUtils/Install.pm.orig	Fri Feb 23 03:57:55 2001
+++ lib/ExtUtils/Install.pm	Wed Jul 10 17:57:13 2002
@@ -132,7 +132,7 @@
 		$diff++;
 	    }
 
-	    if ($diff){
+	    if ($diff||1){
 		if (-f $targetfile){
 		    forceunlink($targetfile) unless $nonono;
 		} else {
@@ -156,7 +156,7 @@
 	    } else {
 		inc_uninstall($_,$File::Find::dir,$verbose,0); # nonono set to 0
 	    }
-	    $packlist->{$origfile}++;
+	    $packlist->{$targetfile}++;
 
 	}, ".");
 	chdir($cwd) or Carp::croak("Couldn't chdir to $cwd: $!");
