--- PDFJ/Object.pm.orig	Thu Oct 24 16:32:34 2002
+++ PDFJ/Object.pm	Thu Oct 24 16:37:38 2002
@@ -133,6 +133,7 @@
 
 sub makeoutput {
 	my $self = shift;
+	$self->{outputtype} = "" if (not defined $self->{outputtype});
 	if( $self->{outputtype} !~ /^(literal|hex|hexliteral)$/ ) {
 		$self->{outputtype} = 
 			$self->{value} =~ /[\x80-\xff]/ ? 'hex' : 'literal';
