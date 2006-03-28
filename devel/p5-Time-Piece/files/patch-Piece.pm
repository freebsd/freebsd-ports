--- ./Piece.pm.orig	Sun Feb 26 20:49:20 2006
+++ ./Piece.pm	Sun Feb 26 20:49:50 2006
@@ -121,6 +121,7 @@
   for my $method (@methods) {
     if (exists $_special_exports{$method}) {
       no strict 'refs';
+      local $^W;
       *{$to . "::$method"} = $_special_exports{$method}->($class);
     } else {
       $class->SUPER::export($to, $method);
