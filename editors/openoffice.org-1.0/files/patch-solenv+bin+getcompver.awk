--- ../solenv/bin/getcompver.awk.orig	Tue May 28 13:09:01 2002
+++ ../solenv/bin/getcompver.awk	Tue May 28 13:08:14 2002
@@ -61,9 +61,11 @@
 #*************************************************************************
 BEGIN {
     CCversion = 0
+    compiler_matched = 0
 }
 # Sun c++ compiler
 /Sun WorkShop/ {
+    compiler_matched = 1
     # version number right after "C++" 
     x = match( $0, /C\+\+ .*/ )
     btwn = substr( $0, RSTART, RLENGTH)
@@ -73,12 +75,28 @@
 }
 # Microsoft c++ compiler
 /Microsoft.*..\...\...../ {
+    compiler_matched = 1
     # match on the format of the ms versions ( dd.dd.dddd )
     x = match( $0, /..\...\...../ )
     CCversion = substr( $0, RSTART, RLENGTH)
 }
+# Java
+/java version/ {
+    compiler_matched = 1
+    # match on the format of the java versions ( d[d].d[d].d[d] )
+    x = match( $0, /".*\..*\..*"/ )
+    CCversion = substr( $0, RSTART+1, RLENGTH-2)
+}
+/^[0-9]*[.][0-9]*$/ {
+    if ( compiler_matched == 0 ) {
+# need to blow to x.xx.xx for comparing
+    	CCversion = $0 ".0"
+    }
+}
 /^[0-9]*[.][0-9]*[.][0-9]*$/ {
-    CCversion = $0
+    if ( compiler_matched == 0 ) {
+        CCversion = $0
+    }
 }
 END {
     if ( num == "true" ) {
