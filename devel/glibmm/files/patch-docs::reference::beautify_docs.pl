--- docs/reference/beautify_docs.pl.in.orig	Thu Feb 12 02:52:02 2004
+++ docs/reference/beautify_docs.pl.in	Thu Feb 12 03:00:08 2004
@@ -25,7 +25,7 @@
   my ($file) = @_;
   my @outbuf;
 
-  open(FILE, '<', $file);
+  open(FILE, "<$file");
 
   while(<FILE>)
   {
@@ -71,7 +71,7 @@
     push(@outbuf, $_);
   }
 
-  open(FILE, '>', $file);
+  open(FILE, ">$file");
 
   # write the whole buffer back
   print FILE "$_" foreach(@outbuf);
