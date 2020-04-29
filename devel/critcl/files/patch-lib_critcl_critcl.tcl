--- lib/critcl/critcl.tcl.orig	2020-04-29 08:46:32 UTC
+++ lib/critcl/critcl.tcl
@@ -2754,7 +2754,7 @@ proc ::critcl::setconfig {targetconfig} {
     # as well.
 
     set v::targetplatform $targetconfig
-    foreach p {gcc cc_r xlc xlc_r cc cl} {
+    foreach p {gcc cc_r xlc xlc_r cc cl clang([[:digit:]])*} {
 	if {[regsub -- "-$p\$" $v::targetplatform {} v::targetplatform]} break
     }
 
