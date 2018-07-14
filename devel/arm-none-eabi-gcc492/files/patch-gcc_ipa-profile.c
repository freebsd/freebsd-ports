--- gcc/ipa-profile.c.orig	2014-01-02 22:23:26 UTC
+++ gcc/ipa-profile.c
@@ -163,7 +163,7 @@ dump_histogram (FILE *file, vec<histogra
     {
       cumulated_time += histogram[i]->count * histogram[i]->time;
       cumulated_size += histogram[i]->size;
-      fprintf (file, "  "HOST_WIDEST_INT_PRINT_DEC": time:%i (%2.2f) size:%i (%2.2f)\n",
+      fprintf (file, "  " HOST_WIDEST_INT_PRINT_DEC ": time:%i (%2.2f) size:%i (%2.2f)\n",
 	       (HOST_WIDEST_INT) histogram[i]->count,
 	       histogram[i]->time,
 	       cumulated_time * 100.0 / overall_time,
@@ -516,7 +516,7 @@ ipa_profile (void)
 	{
 	  gcov_type min, cumulated_time = 0, cumulated_size = 0;
 
-	  fprintf (dump_file, "Overall time: "HOST_WIDEST_INT_PRINT_DEC"\n", 
+	  fprintf (dump_file, "Overall time: " HOST_WIDEST_INT_PRINT_DEC "\n", 
 		   (HOST_WIDEST_INT)overall_time);
 	  min = get_hot_bb_threshold ();
           for (i = 0; i < (int)histogram.length () && histogram[i]->count >= min;
@@ -525,7 +525,7 @@ ipa_profile (void)
 	      cumulated_time += histogram[i]->count * histogram[i]->time;
 	      cumulated_size += histogram[i]->size;
 	    }
-	  fprintf (dump_file, "GCOV min count: "HOST_WIDEST_INT_PRINT_DEC
+	  fprintf (dump_file, "GCOV min count: " HOST_WIDEST_INT_PRINT_DEC
 		   " Time:%3.2f%% Size:%3.2f%%\n", 
 		   (HOST_WIDEST_INT)min,
 		   cumulated_time * 100.0 / overall_time,
@@ -551,7 +551,7 @@ ipa_profile (void)
 	      cumulated_time += histogram[i]->count * histogram[i]->time;
 	      cumulated_size += histogram[i]->size;
 	    }
-	  fprintf (dump_file, "Determined min count: "HOST_WIDEST_INT_PRINT_DEC
+	  fprintf (dump_file, "Determined min count: " HOST_WIDEST_INT_PRINT_DEC
 		   " Time:%3.2f%% Size:%3.2f%%\n", 
 		   (HOST_WIDEST_INT)threshold,
 		   cumulated_time * 100.0 / overall_time,
