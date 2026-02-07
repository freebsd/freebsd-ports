Concatenate CFLAGS passed as argument and the one from Perl

--- Makefile.PL.orig	2025-01-20 08:10:33 UTC
+++ Makefile.PL
@@ -237,6 +237,24 @@ package MY;
 
 package MY;
 
+use Config;
+
+sub cflags {
+    my $self = shift;
+
+    my $default = $Config::Config{ccflags} // '';
+    my $user    = $self->{CCFLAGS}         // '';
+
+    # Merge defaults + user flags, dedupe tokens, keep order so user flags come last
+    my %seen;
+    my @merged = grep { length && !$seen{$_}++ }
+                 split(/\s+/, "$default $user");
+
+    local $self->{CCFLAGS} = join ' ', @merged;
+
+    return $self->SUPER::cflags(@_);
+}
+
 sub postamble {
 warn <<EOT;
 
