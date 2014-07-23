--- ../ZoneParse.pm-orig	2014-07-22 09:36:10.000000000 +0200
+++ lib/DNS/ZoneParse.pm	2014-07-22 11:48:56.000000000 +0200
@@ -17,16 +17,20 @@
 my $rr_class             = qr/(?:IN|HS|CH)/i;
 my $rr_ttl               = qr/(?:\d+[wdhms]?)+/i;
 
-$VERSION = '1.10';
+$VERSION = '1.11';
 my (
-    %dns_id,  %dns_soa, %dns_ns,  %dns_a,     %dns_cname, %dns_mx, %dns_txt,
+    %dns_id,  %dns_soa, %dns_ns,  %dns_a,     %dns_cname, %dns_mx,
+    %dns_txt, %dns_spf,
     %dns_ptr, %dns_a4,  %dns_srv, %dns_hinfo, %dns_rp,    %dns_loc,
     %dns_generate,
     %dns_last_name, %dns_last_origin, %dns_last_class, %dns_last_ttl,
     %dns_found_origins, %unparseable_line_callback, %last_parse_error_count,
 );
 
-my %possibly_quoted = map { $_ => undef } qw/ os cpu text mbox /;
+my %possibly_quoted = map { $_ => undef } qw/ os cpu text mbox spf /;
+
+# https://kb.isc.org/article/AA-00356/0/Can-I-have-a-TXT-or-SPF-record-longer-than-255-characters.html
+my %possibly_multiple = map { $_ => undef } qw/ text spf /;
 
 sub new {
     my $class = shift;
@@ -71,6 +75,7 @@
     delete $dns_cname{$self};
     delete $dns_mx{$self};
     delete $dns_txt{$self};
+    delete $dns_spf{$self};
     delete $dns_ptr{$self};
     delete $dns_a4{$self};
     delete $dns_srv{$self};
@@ -99,6 +104,7 @@
      : $method eq 'cname'    ? $dns_cname{$self}
      : $method eq 'mx'       ? $dns_mx{$self}
      : $method eq 'txt'      ? $dns_txt{$self}
+     : $method eq 'spf'      ? $dns_spf{$self}
      : $method eq 'ptr'      ? $dns_ptr{$self}
      : $method eq 'aaaa'     ? $dns_a4{$self}
      : $method eq 'srv'      ? $dns_srv{$self}
@@ -130,6 +136,7 @@
             MX    => $dns_mx{$self},
             PTR   => $dns_ptr{$self},
             TXT   => $dns_txt{$self},
+            SPF   => $dns_spf{$self},
             SRV   => $dns_srv{$self},
             HINFO => $dns_hinfo{$self},
             RP    => $dns_rp{$self},
@@ -235,7 +242,21 @@
         next unless defined $o;
         next unless $o->{'ORIGIN'} eq $process_this_origin;
         $self->_escape_chars( $o );
-        $output .= qq[$o->{name}	$o->{ttl} $o->{class} TXT	"$o->{text}"\n];
+	my $t = $o->{text};
+	if ( length($t) > 250 ) {
+	    $t=join('" "',( $t =~ m/.{1,250}/g ));
+	}
+        $output .= qq[$o->{name}	$o->{ttl} $o->{class}	TXT	"$t"\n];
+    }
+    foreach my $o ( @{ $dns_spf{$self} } ) {
+        next unless defined $o;
+        next unless $o->{'ORIGIN'} eq $process_this_origin;
+        $self->_escape_chars( $o );
+	my $t = $o->{spf};
+	if ( length($t) > 250 ) {
+	    $t=join('" "',( $t =~ m/.{1,250}/g ));
+	}
+        $output .= qq[$o->{name}	$o->{ttl} $o->{class}	SPF	"$t"\n];
     }
     foreach my $o ( @{ $dns_ptr{$self} } ) {
         next unless defined $o;
@@ -361,6 +382,7 @@
     $dns_cname{$self}     = [];
     $dns_mx{$self}        = [];
     $dns_txt{$self}       = [];
+    $dns_spf{$self}       = [];
     $dns_ptr{$self}       = [];
     $dns_a4{$self}        = [];
     $dns_srv{$self}       = [];
@@ -614,6 +636,20 @@
                     text  => $4,
              } );
         } elsif (
+            /($valid_name)? \s+
+                $ttl_cls
+                SPF \s+
+                ("$valid_quoted_txt_char*(?<!\\)"|$valid_txt_char+)
+            /ixo
+        ) {
+            push @{ $dns_spf{$self} },
+             $self->_massage( {
+                    name  => $1,
+                    ttl   => $2,
+                    class => $3,
+                    spf   => $4,
+             } );
+        } elsif (
             /^\s*\$TTL \s+
                 ($rr_ttl)
             /ixo
@@ -817,9 +853,12 @@
             $record->{$r} = '';
             next;
         }
-        if ( exists $possibly_quoted{$r} ) {
+	if ( exists $possibly_quoted{$r} ) {
+	    if ( exists $possibly_multiple{$r} ) {
+		$record->{$r} =~ s/"\s+"//;
+	    }
             ( $record->{$r} =~ s/^"// ) && ( $record->{$r} =~ s/"$// );
-        }
+	}
 
         # We return email addresses just as they are in the file... for better
         # or worse (mostly for backwards compatability reasons).
@@ -1051,7 +1090,7 @@
 If you plan to pass a on_unparseable_line callback but do not wish to specify
 an C<$origin>, pass 'undef' as the C<$origin> parameter.
 
-=item a(), cname(), srv(), mx(), ns(), ptr(), txt(), hinfo(), rp(), loc()
+=item a(), cname(), srv(), mx(), ns(), ptr(), txt(), spf(), hinfo(), rp(), loc()
 
 These methods return references to the resource records. For example:
 
@@ -1069,6 +1108,9 @@
 TXT records also have a 'text' property representing the record's 'txt-data'
 descriptive text.
 
+SPF records also have a 'spf' property representing the record's 'spf-data'
+descriptive text.
+
 HINFO records also have 'cpu' and 'os' properties.
 
 RP records also have 'mbox' and 'text' properties.
