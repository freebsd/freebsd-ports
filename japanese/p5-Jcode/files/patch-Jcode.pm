--- Jcode.pm.orig	Mon Mar 29 20:49:24 2004
+++ Jcode.pm	Mon Mar 29 20:50:01 2004
@@ -198,7 +198,7 @@
 folds lines in jcode string every $bytes_per_line (default: 72) 
 in a way that does not clobber the multibyte string.
 (Sorry, no Kinsoku done!)
-with a newline string spified by $newline_str (default: \n).  
+with a newline string specified by $newline_str (default: \n).  
 
 =back
 
@@ -210,7 +210,7 @@
     $bpl ||= 72;
     $nl  ||= "\n";
     my $r_str = $self->[0];
-    my (@lines, $len, $i);
+    my ($i, $len, @lines) = (0, 0);
     while ($$r_str =~
 	   m/($RE{EUC_0212}|$RE{EUC_KANA}|$RE{EUC_C}|[\x00-\xff])/sgo)
     {
