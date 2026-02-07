--- gmusicbrowser.pl.orig	2019-02-23 05:33:24 UTC
+++ gmusicbrowser.pl
@@ -8977,7 +8977,7 @@ sub Set
 
 	($cmd,my $pattern)= split /:/,$cmd,2;
 	$pattern='' unless defined $pattern;
-	my ($basecmd,my $prop)= Songs::filter_properties($field,"$cmd:$pattern");
+	my ($basecmd,$prop)= Songs::filter_properties($field,"$cmd:$pattern");
 	if (!$prop)
 	{	$cmd=  Songs::Field_property($field,'default_filter');
 		($basecmd,$prop)= Songs::filter_properties($field,$cmd);
