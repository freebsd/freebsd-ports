--- ChaSen.pm.orig	Thu Aug 19 17:20:15 1999
+++ ChaSen.pm	Sun Feb 27 02:05:45 2000
@@ -11,8 +11,8 @@
 
  use Text::ChaSen;
 
- $res = chasen::getopt_argv('chasen-perl', '-j', '-F', '%m ');
- $str = chasen::sparse_tostr("日本語の文字列");
+ $res = Text::ChaSen::getopt_argv('chasen-perl', '-j', '-F', '%m ');
+ $str = Text::ChaSen::sparse_tostr("日本語の文字列");
 
 =head1 DESCRIPTION
 
