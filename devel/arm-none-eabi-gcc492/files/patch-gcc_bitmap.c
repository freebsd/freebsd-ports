--- gcc/bitmap.c.orig	2014-01-02 22:23:26 UTC
+++ gcc/bitmap.c
@@ -2166,9 +2166,9 @@ print_statistics (bitmap_descriptor_d **
       s[41] = 0;
       fprintf (stderr,
 	       "%-41s %9u"
-	       " %15"HOST_WIDEST_INT_PRINT"d %15"HOST_WIDEST_INT_PRINT"d"
-	       " %15"HOST_WIDEST_INT_PRINT"d"
-	       " %10"HOST_WIDEST_INT_PRINT"d %10"HOST_WIDEST_INT_PRINT"d\n",
+	       " %15" HOST_WIDEST_INT_PRINT "d %15" HOST_WIDEST_INT_PRINT "d"
+	       " %15" HOST_WIDEST_INT_PRINT "d"
+	       " %10" HOST_WIDEST_INT_PRINT "d %10" HOST_WIDEST_INT_PRINT "d\n",
 	       s, d->created,
 	       d->allocated, d->peak, d->current,
 	       d->nsearches, d->search_iter);
@@ -2201,7 +2201,7 @@ dump_bitmap_statistics (void)
   bitmap_desc_hash.traverse <output_info *, print_statistics> (&info);
   fprintf (stderr, "---------------------------------------------------------------------------------\n");
   fprintf (stderr,
-	   "%-41s %9"HOST_WIDEST_INT_PRINT"d %15"HOST_WIDEST_INT_PRINT"d\n",
+	   "%-41s %9" HOST_WIDEST_INT_PRINT "d %15" HOST_WIDEST_INT_PRINT "d\n",
 	   "Total", info.count, info.size);
   fprintf (stderr, "---------------------------------------------------------------------------------\n");
 }
