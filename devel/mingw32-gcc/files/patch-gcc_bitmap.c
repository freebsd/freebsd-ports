--- gcc/bitmap.c.orig	2013-03-07 17:27:52 UTC
+++ gcc/bitmap.c
@@ -2159,9 +2159,9 @@ print_statistics (void **slot, void *b)
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
@@ -2194,7 +2194,7 @@ dump_bitmap_statistics (void)
   htab_traverse (bitmap_desc_hash, print_statistics, &info);
   fprintf (stderr, "---------------------------------------------------------------------------------\n");
   fprintf (stderr,
-	   "%-41s %9"HOST_WIDEST_INT_PRINT"d %15"HOST_WIDEST_INT_PRINT"d\n",
+	   "%-41s %9" HOST_WIDEST_INT_PRINT "d %15" HOST_WIDEST_INT_PRINT "d\n",
 	   "Total", info.count, info.size);
   fprintf (stderr, "---------------------------------------------------------------------------------\n");
 }
