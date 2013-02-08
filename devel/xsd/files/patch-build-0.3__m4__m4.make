Use gm4 from devel/m4, as base m4 lacks some features needed by this build
system.
--- build-0.3/m4/m4.make~	2012-08-10 22:56:20.000000000 -0300
+++ build-0.3/m4/m4.make	2012-08-10 22:56:27.000000000 -0300
@@ -3,7 +3,7 @@
 # copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
 # license   : GNU GPL v2; see accompanying LICENSE file
 
-$(out_base)/%: m4 := m4
+$(out_base)/%: m4 := gm4
 $(out_base)/%: m4_options +=
 
 ifeq ($(out_base),$(src_base))
