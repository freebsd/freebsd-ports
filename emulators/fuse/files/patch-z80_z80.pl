--- z80/z80.pl.orig	Sat Sep 13 16:53:54 2003
+++ z80/z80.pl	Tue Oct 28 13:00:53 2003
@@ -1128,9 +1128,10 @@
 
     {
 	no strict qw( refs );
+	my $func = "opcode_$opcode";
 
-	if( exists &{ "opcode_$opcode" } ) {
-	    "opcode_$opcode"->( @arguments );
+	if( defined (&$func) ) {
+	    &$func( @arguments );
 	}
     }
 
