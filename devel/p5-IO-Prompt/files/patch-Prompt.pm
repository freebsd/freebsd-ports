--- lib/IO/Prompt.pm
+++ lib/IO/Prompt.pm
@@ -88,6 +88,7 @@
     @data = map { $flags_alias{$_} || $_ } @data;
     for (my $i = 0 ; $i < @data ; $i++) {
         local *_ = \($data[$i]);
+	next unless defined $_;
         if (ref eq 'HASH') {
             splice @data, $i + 1, 0, %$_;
         }
