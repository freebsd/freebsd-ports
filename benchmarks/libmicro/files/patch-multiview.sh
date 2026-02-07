--- multiview.sh.orig	2011-05-11 00:58:23 UTC
+++ multiview.sh
@@ -38,15 +38,15 @@
 #	the redder the color, the slower the result, the greener the
 #       faster
  
-/bin/nawk '	BEGIN { 
+/usr/bin/awk '	BEGIN { 
   benchmark_count = 0;
   header_count = 0;
 }
 /^#/ {
-	continue;
+	next;
 	}
 /errors/ {
-	continue;
+	next;
 	}
 /^\!/ { 
 	split($0, A_header, ":"); 
@@ -57,7 +57,7 @@
 		header_names[name] = ++header_count;
 		headers[header_count] = name;
 	}
-	continue;
+	next;
 }
 
 	{ 
@@ -136,7 +136,7 @@ END { 
 				
 			for (j = 2; j < ARGC; j++) 
 				printf("<td>%s</td>\n", "not computed");
-			continue;
+			next;
 		}
 
 		for (j = 2; j < ARGC; j++) {
