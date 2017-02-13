--- jartool.c.orig	2006-08-07 08:06:23 UTC
+++ jartool.c
@@ -313,7 +313,7 @@ int number_of_entries; /* number of entr
 const char *progname;
 
 /* The offset of the end of the last zip entry. */
-ub4 end_of_entries;
+off_t end_of_entries;
 
 /* This is used to mark options with no short value.  */
 #define LONG_OPT(Num)  ((Num) + 128)
