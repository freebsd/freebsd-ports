--- scripts/texi2pod.pl.orig	2015-11-03 20:01:35 UTC
+++ scripts/texi2pod.pl
@@ -317,7 +317,7 @@ while(<$inf>) {
 	@columns = ();
 	for $column (split (/\s*\@tab\s*/, $1)) {
 	    # @strong{...} is used a @headitem work-alike
-	    $column =~ s/^\@strong{(.*)}$/$1/;
+	    $column =~ s/^\@strong\{(.*)\}$/$1/;
 	    push @columns, $column;
 	}
 	$_ = "\n=item ".join (" : ", @columns)."\n";
