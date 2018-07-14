--- gcc/value-prof.c.orig	2014-01-02 22:23:26 UTC
+++ gcc/value-prof.c
@@ -266,10 +266,10 @@ dump_histogram_value (FILE *dump_file, h
 	   unsigned int i;
 	   fprintf (dump_file, " [");
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
@@ -279,8 +279,8 @@ dump_histogram_value (FILE *dump_file, h
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
@@ -291,9 +291,9 @@ dump_histogram_value (FILE *dump_file, h
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
@@ -305,8 +305,8 @@ dump_histogram_value (FILE *dump_file, h
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
@@ -317,7 +317,7 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "IOR value ");
       if (hist->hvalue.counters)
 	{
-	   fprintf (dump_file, "ior:"HOST_WIDEST_INT_PRINT_DEC,
+	   fprintf (dump_file, "ior:" HOST_WIDEST_INT_PRINT_DEC,
 		    (HOST_WIDEST_INT) hist->hvalue.counters[0]);
 	}
       fprintf (dump_file, ".\n");
@@ -327,9 +327,9 @@ dump_histogram_value (FILE *dump_file, h
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
@@ -340,9 +340,9 @@ dump_histogram_value (FILE *dump_file, h
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
@@ -353,7 +353,7 @@ dump_histogram_value (FILE *dump_file, h
       fprintf (dump_file, "Time profile ");
       if (hist->hvalue.counters)
       {
-        fprintf (dump_file, "time:"HOST_WIDEST_INT_PRINT_DEC,
+        fprintf (dump_file, "time:" HOST_WIDEST_INT_PRINT_DEC,
                  (HOST_WIDEST_INT) hist->hvalue.counters[0]);
       }
       fprintf (dump_file, ".\n");
@@ -1533,8 +1533,8 @@ gimple_ic_transform (gimple_stmt_iterato
       print_generic_expr (dump_file, direct_call->decl, TDF_SLIM);
       fprintf (dump_file, " transformation on insn postponned to ipa-profile");
       print_gimple_stmt (dump_file, stmt, 0, TDF_SLIM);
-      fprintf (dump_file, "hist->count "HOST_WIDEST_INT_PRINT_DEC
-	       " hist->all "HOST_WIDEST_INT_PRINT_DEC"\n", count, all);
+      fprintf (dump_file, "hist->count " HOST_WIDEST_INT_PRINT_DEC
+	       " hist->all " HOST_WIDEST_INT_PRINT_DEC "\n", count, all);
     }
 
   return true;
