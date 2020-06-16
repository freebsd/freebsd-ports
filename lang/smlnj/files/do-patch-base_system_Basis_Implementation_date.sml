--- base/system/Basis/Implementation/date.sml.orig	2019-06-12 21:16:48 UTC
+++ base/system/Basis/Implementation/date.sml
@@ -70,7 +70,7 @@ structure Date : DATE =
 	  = wrap (CInterface.c_function "SMLNJ-Date" "strfTime")
 
   (* conversions between integer numbers of seconds (used by runtime) and Time.time values *)
-    fun nsToTime s = Time.fromSeconds (Word64.toLargeInt s)
+    fun nsToTime s = Time.fromNanoseconds (Word64.toLargeInt s)
     fun timeToNs t = Word64.fromLargeInt (Time.toNanoseconds t)
 
     val localTime = localTime' o timeToNs
