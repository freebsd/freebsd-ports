--- lib/Deputy.pm.orig	Mon Mar 19 10:13:52 2007
+++ lib/Deputy.pm	Mon Mar 19 10:15:42 2007
@@ -154,7 +154,7 @@
     my @args = @{$ppargs};
     unshift @args,
     $self->forceIncludeArg("$::deputyhome/include/deputy/annots.h");
-    unshift @args, $self->{INCARG} . $::deputyhome . "/include";
+    unshift @args, $self->{INCARG} . "$::deputyhome" . "/include";
     return $self->SUPER::preprocess_before_cil($src, $dest, \@args);
 }
 
