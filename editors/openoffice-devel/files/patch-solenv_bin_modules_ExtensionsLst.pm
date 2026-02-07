--- solenv/bin/modules/ExtensionsLst.pm.orig	2014-02-25 08:33:31 UTC
+++ solenv/bin/modules/ExtensionsLst.pm
@@ -592,8 +592,9 @@ sub GetExtensionList ($@)
     my $protocol_selector = shift;
     my @language_list = @_;
 
-    if (defined $ENV{'ENABLE_BUNDLED_DICTIONARIES'}
+    if ((defined $ENV{'ENABLE_BUNDLED_DICTIONARIES'}
          && $ENV{'ENABLE_BUNDLED_DICTIONARIES'} eq "YES")
+	 || $protocol_selector eq "file")
     {
         my $full_file_name = Prepare();
         my @urls = ParseExtensionsLst($full_file_name, \@language_list);
