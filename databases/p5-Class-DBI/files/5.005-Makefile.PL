--- Makefile.PL~	Wed Jan  7 15:01:06 2004
+++ Makefile.PL	Tue Mar 16 17:11:54 2004
@@ -7,8 +7,6 @@
 ($PACKAGE_FILE) = $PACKAGE =~ /::([^:]+)/;
 $LAST_API_CHANGE = 0.93;
 
-require 5.006;
-
 eval "require $PACKAGE";
 
 unless ($@) { # Make sure we did find the module.
