--- bin/jruby.sh.orig	Fri Sep 13 05:24:44 2002
+++ bin/jruby.sh	Wed Oct  9 02:36:39 2002
@@ -22,2 +22,4 @@
 
+JRUBY_HOME="${JRUBY_HOME:-!!JRUBY_HOME!!}"
+
 if [ -z "$JRUBY_HOME" ] ; then
