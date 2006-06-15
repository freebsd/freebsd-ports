--- PayflowPro.pm.orig	Tue Jun 13 01:30:27 2006
+++ PayflowPro.pm	Tue Jun 13 01:30:41 2006
@@ -14,7 +14,7 @@
 @ISA = qw(Exporter AutoLoader Business::OnlinePayment);
 @EXPORT = qw();
 @EXPORT_OK = qw();
-$VERSION = '0.02';
+$VERSION = '0.03';
 
 sub set_defaults {
     my $self = shift;
