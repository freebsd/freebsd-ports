$FreeBSD$

--- lib/ExtUtils/Install.pm.orig	Sun Jun 16 13:36:29 2002
+++ lib/ExtUtils/Install.pm	Sun Jun 16 13:36:50 2002
@@ -156,7 +156,7 @@
 	    } else {
 		inc_uninstall($_,$File::Find::dir,$verbose,0); # nonono set to 0
 	    }
-	    $packlist->{$origfile}++;
+	    $packlist->{$targetfile}++;
 
 	}, ".");
 	chdir($cwd) or Carp::croak("Couldn't chdir to $cwd: $!");
