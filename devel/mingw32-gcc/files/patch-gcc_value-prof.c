--- gcc/value-prof.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/value-prof.c
@@ -250,10 +250,10 @@ dump_histogram_value (FILE *dump_file, h
 	   unsigned int i;
 	   fprintf(dump_file, " [");
            for (i = 0; i < hist->hdata.intvl.steps; i++)
-	     fprintf (dump_file, " %d:"HOST_WIDEST_INT_PRINT_DEC,
+	     fprintf (dump_file, " %d:" HOST_WIDEST_INT_PRINT_DEC,
 		      hist->hdata.intvl.int_start + i,
 		      (HOST_WIDEST_INT) hist->hvalue.counters[i]);
-	   fprintf (dump_file, " ] outside range:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, " ] outside range:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[i]);
 	}
       fprintf (dump_file, ".\n");
@@ -263,8 +263,8 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Pow2 counter ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "pow2:"HOST_WIDEST_INT_PRINT_DEC
-		    " nonpow2:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "pow2:" HOST_WIDEST_INT_PRINT_DEC
+		    " nonpow2:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[1]);
 	}
@@ -275,9 +275,9 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Single value ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "value:"HOST_WIDEST_INT_PRINT_DEC
-		    " match:"HOST_WIDEST_INT_PRINT_DEC
-		    " wrong:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "value:" HOST_WIDEST_INT_PRINT_DEC
+		    " match:" HOST_WIDEST_INT_PRINT_DEC
+		    " wrong:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[1],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[2]);
@@ -289,8 +289,8 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Average value ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "sum:"HOST_WIDEST_INT_PRINT_DEC
-		    " times:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "sum:" HOST_WIDEST_INT_PRINT_DEC
+		    " times:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[1]);
 	}
@@ -301,7 +301,7 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "IOR value ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "ior:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "ior:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0]);
 	}
       fprintf (dump_file, ".\n");
@@ -311,9 +311,9 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Constant delta ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "value:"HOST_WIDEST_INT_PRINT_DEC
-		    " match:"HOST_WIDEST_INT_PRINT_DEC
-		    " wrong:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "value:" HOST_WIDEST_INT_PRINT_DEC
+		    " match:" HOST_WIDEST_INT_PRINT_DEC
+		    " wrong:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[1],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[2]);
@@ -324,9 +324,9 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Indirect call ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "value:"HOST_WIDEST_INT_PRINT_DEC
-		    " match:"HOST_WIDEST_INT_PRINT_DEC
-		    " all:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "value:" HOST_WIDEST_INT_PRINT_DEC
+		    " match:" HOST_WIDEST_INT_PRINT_DEC
+		    " all:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[1],
 		    (HOST_WIDEST_INT) hist->hvalue.counters[2]);
@@ -1363,8 +1363,8 @@ gimple_ic_transform (gimple_stmt_iterato
       print_gimple_stmt (dump_file, stmt, 0, TDF_SLIM);
       fprintf (dump_file, " to ");
       print_gimple_stmt (dump_file, modify, 0, TDF_SLIM);
-      fprintf (dump_file, "hist->count "HOST_WIDEST_INT_PRINT_DEC
-	       " hist->all "HOST_WIDEST_INT_PRINT_DEC"\n", count, all);
+      fprintf (dump_file, "hist->count " HOST_WIDEST_INT_PRINT_DEC
+	       " hist->all " HOST_WIDEST_INT_PRINT_DEC "\n", count, all);
     }
 
   return true;
