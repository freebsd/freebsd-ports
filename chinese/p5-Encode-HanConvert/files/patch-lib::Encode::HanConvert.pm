--- lib/Encode/HanConvert.pm.orig	Wed May 28 04:45:44 2003
+++ lib/Encode/HanConvert.pm	Wed May 28 04:46:39 2003
@@ -111,8 +111,6 @@
 
 __END__
 
-=for encoding big5
-
 =head1 NAME
 
 Encode::HanConvert - Traditional and Simplified Chinese mappings
@@ -204,6 +202,8 @@
     print BIG5, <EUC>;
 
 Or, more interestingly:
+
+=for encoding big5
 
     use encoding 'big5-simp';
     print "¤¤¤å"; # prints simplified Chinese in unicode
