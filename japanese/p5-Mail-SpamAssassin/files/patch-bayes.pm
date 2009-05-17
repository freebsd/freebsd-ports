--- Bayes.pm.orig      2008-06-10 05:20:22.000000000 -0400
+++ lib/Mail/SpamAssassin/Bayes.pm     2008-08-22 03:23:38.000000000 -0400
@@ -145,6 +145,7 @@
 # hapaxen they generate.
 $MARK_PRESENCE_ONLY_HDRS = qr{(?: X-Face
   |X-(?:Gnu-?PG|PGP|GPG)(?:-Key)?-Fingerprint
+  |D(?:KIM|omainKey)-Signature
 )}ix;
 
 # tweaks tested as of Nov 18 2002 by jm: see SpamAssassin-devel list archives
