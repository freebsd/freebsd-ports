--- lib/BZ/Client/XMLRPC/Value.pm.orig	2014-06-22 04:55:15.521928171 +0600
+++ lib/BZ/Client/XMLRPC/Value.pm	2014-06-22 04:56:11.104922485 +0600
@@ -71,7 +71,11 @@
             $self->{'level1_content'} = undef;
             $self->{'level1_elem'} = undef;
             if ("dateTime.iso8601" eq $name) {
-               $self->{'result'} = DateTime::Format::ISO8601->parse_datetime( $self->{'result'} );
+		my $val = $self->{'result'};
+		if ($val =~ /(\d\d\d\d)(\d\d)(\d\d)(T\d\d:\d\d:\d\d)/) {
+			$val = "$1-$2-$3$4";
+		}
+		$self->{'result'} = DateTime::Format::ISO8601->parse_datetime( $val );
             }            
         }
     }
