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
