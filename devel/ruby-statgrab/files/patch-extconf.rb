--- ./extconf.rb.orig	2008-04-28 01:39:02.000000000 +0100
+++ ./extconf.rb	2014-05-10 02:17:32.621965686 +0100
@@ -1,3 +1,4 @@
 require 'mkmf'
-have_library("statgrab")
+pkg_config('libstatgrab0')
+have_library("statgrab0")
 create_makefile("statgrab")
