--- String.pm~	Tue Mar 11 04:16:42 2003
+++ String.pm	Fri May  2 15:26:38 2003
@@ -128,7 +128,8 @@
     # This is different from perl's normal behaviour by not letting
     # a U+0030  ("0") be false.
     my $self = shift;
-    $$self ? 1 : "";
+    my $a = $$self;
+    $a ? 1 : "";
 }
 
 
