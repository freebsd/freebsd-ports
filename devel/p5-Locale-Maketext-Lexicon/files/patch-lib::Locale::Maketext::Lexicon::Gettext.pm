--- lib/Locale/Maketext/Lexicon/Gettext.pm~	Thu Dec  5 07:36:16 2002
+++ lib/Locale/Maketext/Lexicon/Gettext.pm	Thu Apr 10 17:26:52 2003
@@ -101,7 +101,7 @@
 	} :
 
 	/^"(.*)" *$/			? do {	# continued strings
-	    $var{$key} .= $1."\n";
+	    $var{$key} .= $1;
 	} :
 
 	/^#, +(.*) *$/			? do {	# control variables
