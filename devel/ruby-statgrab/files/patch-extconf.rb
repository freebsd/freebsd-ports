--- ./extconf.rb.orig	2008-06-16 20:37:28.000000000 +0100
+++ ./extconf.rb	2008-06-16 20:37:35.000000000 +0100
@@ -1,3 +1,4 @@
 require 'mkmf'
+pkg_config('libstatgrab')
 have_library("statgrab")
 create_makefile("statgrab")
