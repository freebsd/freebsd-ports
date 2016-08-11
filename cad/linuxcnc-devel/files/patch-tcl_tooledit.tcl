--- tcl/tooledit.tcl.orig	2016-06-25 02:19:12 UTC
+++ tcl/tooledit.tcl
@@ -1,4 +1,4 @@
-#!/usr/bin/wish
+#!/usr/bin/env wish8.6
 #
 # Copyright: 2009-2012
 # Author:    Dewey Garrett <dgarrett@panix.com>
@@ -345,14 +345,14 @@ proc ::tooledit::watch {args} {
   switch $args {
     start {
       set ::te(mtime) $mtime
-      set ::te(md5sum) [eval exec md5sum $::te(filename)]
+      set ::te(md5sum) [eval exec md5 $::te(filename)]
     }
     stop  {return}
     default {
       if {$mtime > $::te(mtime)} {
         set ::te(mtime) $mtime
         set md5sum $::te(md5sum)
-        set ::te(md5sum) [eval exec md5sum $::te(filename)]
+        set ::te(md5sum) [eval exec md5 $::te(filename)]
         # no message if file contents unchanged
         if {"$md5sum" != "$::te(md5sum)"} {
           ::tooledit::message changed
