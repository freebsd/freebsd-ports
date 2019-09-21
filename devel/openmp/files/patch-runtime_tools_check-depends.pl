Adjust for FreeBSD readelf(1) output.
https://sourceforge.net/p/elftoolchain/tickets/544/

--- runtime/tools/check-depends.pl.orig	2019-01-19 10:56:40 UTC
+++ runtime/tools/check-depends.pl
@@ -131,7 +131,7 @@ sub get_deps_readelf($) {
     # Parse body.
     while ( $i < @bulk ) {
         my $line = $bulk[ $i ];
-        if ( $line !~ m{^\s*0x[0-9a-f]+\s+\(([_A-Z0-9]+)\)\s+(.*)\s*$}i ) {
+        if ( $line !~ m{^\s*0x[0-9a-f]+\s+\(?([_A-Z0-9]+)\)?\s+(.*)\s*$}i ) {
             parse_error( $tool, @bulk, $i );
         }; # if
         my ( $type, $value ) = ( $1, $2 );
