--- etc/texi2pod.pl.orig	2021-08-30 17:17:09 UTC
+++ etc/texi2pod.pl
@@ -59,6 +59,8 @@ while ($_ = shift) {
 	    $flag = shift;
 	}
         push (@ipath, $flag);
+    } elsif (/^--no-split$/) {
+	# ignore option for makeinfo compatibility
     } elsif (/^-/) {
 	usage();
     } else {
