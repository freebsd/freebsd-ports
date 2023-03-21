--- data/db/english/english.awk.orig	2023-03-20 04:01:48 UTC
+++ data/db/english/english.awk
@@ -16,10 +16,10 @@ BEGIN {
 }
 
     # Insert data into english table
-    {   printf "INSERT INTO english (word, freq) VALUES (\"%s\", \"%f\");\n", $1, $2}
+    {   printf "INSERT INTO english (word, freq) VALUES (\'%s\', \'%f\');\n", $1, $2}
 
     #quit sqlite3
 END {
     # Commit the transcation
     print "COMMIT;"
-}
\ No newline at end of file
+}
