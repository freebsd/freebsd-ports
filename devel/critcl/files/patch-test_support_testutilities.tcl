--- test/support/testutilities.tcl.orig	2017-10-24 11:30:43 UTC
+++ test/support/testutilities.tcl
@@ -4,6 +4,9 @@
 #                                          <akupries@shaw.ca>
 #                                          <andreas.kupries@gmail.com>
 
+set auto_path [linsert $auto_path 0 \
+    [file join [file dirname [file dirname [file dirname [info script]]]] lib]]
+
 namespace eval ::tcllib::testutils {
     variable version 1.2
     variable self    [file dirname [file join [pwd] [info script]]]
