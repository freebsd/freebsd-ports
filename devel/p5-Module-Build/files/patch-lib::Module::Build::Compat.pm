--- lib/Module/Build/Compat.pm~	Sun Jan 11 05:19:59 2004
+++ lib/Module/Build/Compat.pm	Tue Jan 13 14:44:22 2004
@@ -144,7 +144,7 @@
 	$perl -e unlink -e shift $makefile
 
 force_do_it :
-	@
+
 EOF
 
   # XXX - user might be using a different subclass
