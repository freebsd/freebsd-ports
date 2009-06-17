--- lib/fastri/util.rb.orig	2009-06-17 16:15:24.000000000 +0400
+++ lib/fastri/util.rb	2009-06-17 16:15:32.000000000 +0400
@@ -1,5 +1,7 @@
 # Copyright (C) 2006  Mauricio Fernandez <mfp@acm.org>
 
+require 'rubygems'
+
 # emulate rubygems.rb and define Gem.path if not loaded
 # This is much faster than requiring rubygems.rb, which loads way too much
 # stuff.
