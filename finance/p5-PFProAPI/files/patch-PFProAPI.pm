--- PFProAPI.pm.orig	Fri Jun 16 01:37:04 2006
+++ PFProAPI.pm	Fri Jun 16 01:37:13 2006
@@ -76,6 +76,11 @@
   my $parmlist;
   my ($name, $value);
 
+  # If no PFPRO_CERT_PATH set, we will set default one
+  if ($ENV{'PFPRO_CERT_PATH'} eq '') {
+    $ENV{'PFPRO_CERT_PATH'} = '%%PREFIX%%/etc/pfpro/certs';
+  }
+
   if (! $data)   {
     # If no data was passed, we will build a test transaction
     $data->{ACCT}    = "5105105105105100";
