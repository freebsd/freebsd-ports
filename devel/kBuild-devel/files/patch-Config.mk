--- Config.kmk.orig	2011-08-05 14:26:26.000000000 +0200
+++ Config.kmk	2011-08-05 14:27:04.000000000 +0200
@@ -105,6 +105,9 @@
 if1of ($(KBUILD_TARGET), openbsd)
  TOOL_FLEX_LEX = gflex
 endif
+if1of ($(KBUILD_TARGET), freebsd)
+ TOOL_FLEX_LEX = %%LOCALBASE%%/bin/flex
+endif
 
 #
 # The OS and Architecture indicators.
