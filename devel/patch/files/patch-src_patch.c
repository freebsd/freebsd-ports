--- src/patch.c.orig	2025-02-27 13:33:25 UTC
+++ src/patch.c
@@ -204,7 +204,10 @@ main (int argc, char **argv)
 
     init_output (&outstate);
     if (outfile)
-      outstate.ofp = open_outfile (outfile);
+      {
+        outstate.ofp = open_outfile (outfile);
+        read_only_behavior = RO_IGNORE;
+      }
 
     /* Make sure we clean up in case of disaster.  */
     init_signals ();
@@ -323,7 +326,8 @@ main (int argc, char **argv)
 	    }
 	}
 
-      if (read_only_behavior != RO_IGNORE
+      if (! skip_rest_of_patch
+	  && read_only_behavior != RO_IGNORE
 	  && ! inerrno && ! S_ISLNK (instat.st_mode)
 	  && safe_access (inname, W_OK) != 0)
 	{
@@ -616,7 +620,7 @@ main (int argc, char **argv)
 		      struct stat outstat;
 
 		      if (stat_file (outname, &outstat) != 0)
-			say ("Cannot stat file %s, skipping backup\n", outname);
+			say ("Cannot stat file %s, skipping backup\n", quotearg (outname));
 		      else
 			output_file (&(struct outfile) { .name = outname },
 				     &outstat, nullptr, nullptr,
@@ -750,7 +754,7 @@ reinitialize_almost_everything (void)
 }
 
 static char const shortopts[] = "bB:cd:D:eEfF:g:i:l"
-#if 0 && defined ENABLE_MERGE
+#if defined ENABLE_MERGE
 				"m"
 #endif
 				"nNo:p:r:RstTuvV:x:Y:z:Z";
