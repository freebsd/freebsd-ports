Index: subversion/libsvn_subr/time.c
===================================================================
--- subversion/libsvn_subr/time.c	(revision 9636)
+++ subversion/libsvn_subr/time.c	(working copy)
@@ -55,7 +55,7 @@
  * compatibility, but no longer generated.
  */
 static const char * const old_timestamp_format =
-"%s %d %s %d %02d:%02d:%02d.%06d (day %03d, dst %d, gmt_off %06d)";
+"%3s %d %3s %d %02d:%02d:%02d.%06d (day %03d, dst %d, gmt_off %06d)";
 
 /* Our human representation of dates looks like this:
  *
