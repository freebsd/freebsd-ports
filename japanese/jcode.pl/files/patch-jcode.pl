--- jcode.pl.orig	2017-09-23 14:20:47 UTC
+++ jcode.pl
@@ -681,7 +681,7 @@ sub __z2h_jis {
 
 sub z2h_euc {
     local(*s, $n) = @_;
-    &init_z2h_euc unless defined %z2h_euc;
+    &init_z2h_euc unless %z2h_euc;
     $s =~ s/($re_euc_c|$re_euc_kana)/
 	$z2h_euc{$1} ? ($n++, $z2h_euc{$1}) : $1
     /geo;
@@ -690,7 +690,7 @@ sub z2h_euc {
 
 sub z2h_sjis {
     local(*s, $n) = @_;
-    &init_z2h_sjis unless defined %z2h_sjis;
+    &init_z2h_sjis unless %z2h_sjis;
     $s =~ s/($re_sjis_c)/$z2h_sjis{$1} ? ($n++, $z2h_sjis{$1}) : $1/geo;
     $n;
 }
