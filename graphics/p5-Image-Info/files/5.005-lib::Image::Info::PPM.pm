--- lib/Image/Info/PPM.pm~	Mon Oct  6 18:38:53 2003
+++ lib/Image/Info/PPM.pm	Mon Mar 22 14:29:29 2004
@@ -39,7 +39,8 @@
 	    $type = shift(@header);
 	    $type =~ s/^P// || die;
 	    $binary++ if $type > 3;
-	    $type = "p" . qw/p b g/[$type % 3] . "m";
+	    my @typetmp = qw/p b g/;
+	    $type = "p" . $typetmp[$type % 3] . "m";
 	    $num_wanted = 2 if $type eq "pbm";
 	}
 
