--- lib/SQL/Translator/Utils.pm.orig	Mon Feb  9 23:04:26 2004
+++ lib/SQL/Translator/Utils.pm	Sun May  9 19:11:27 2004
@@ -123,7 +123,7 @@
 # arguments.  Modified to also handle a list of references.
 # ----------------------------------------------------------------------
 sub parse_list_arg {
-    my $list = UNIVERSAL::isa( $_[0], 'ARRAY' ) ? shift : [ @_ ];
+    my $list = UNIVERSAL::isa( $_[0]||'', 'ARRAY' ) ? shift : [ @_ ];
 
     #
     # This protects stringification of references.
