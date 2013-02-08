--- multiview.sh.orig	Wed Aug 17 22:48:57 2005
+++ multiview.sh	Wed Aug 17 22:49:00 2005
@@ -40,15 +40,15 @@
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
@@ -59,7 +59,7 @@
 		header_names[name] = ++header_count;
 		headers[header_count] = name;
 	}
-	continue;
+	next;
 }
 
 	{ 
@@ -136,7 +136,7 @@
 				
 			for (j = 2; j < ARGC; j++) 
 				printf("<td>%s</td>\n", "not computed");
-			continue;
+			next;
 		}
 
 		for (j = 2; j < ARGC; j++) {
