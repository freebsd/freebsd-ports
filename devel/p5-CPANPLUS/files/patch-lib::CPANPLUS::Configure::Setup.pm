--- lib/CPANPLUS/Configure/Setup.pm.orig	Sat Feb 12 01:04:03 2005
+++ lib/CPANPLUS/Configure/Setup.pm	Sat Feb 12 01:06:04 2005
@@ -212,11 +212,14 @@
         $choices = [$default, $other];
     }
 
+=leeym
     my $loc     = $term->get_reply(
                     prompt  => loc("Location of the Configuration file"),
                     default => $default,
                     choices => $choices,
               );
+=cut
+    my $loc = $default;
 
 
     $self->custom_config(1) unless $loc eq $default;
