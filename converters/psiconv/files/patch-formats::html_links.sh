
$FreeBSD$

--- formats/html_links.sh	2001/08/21 13:34:26	1.1
+++ formats/html_links.sh	2001/08/21 13:37:05
@@ -1,8 +1,8 @@
 #!/bin/sh
 
-function generate_links
+generate_links()
 {
-  local index_file name file lineno
+  #local index_file name file lineno
 
   index_file="$1"
   
@@ -17,9 +17,9 @@
   eval "$command"
 }
 
-function generate_headers
+generate_headers()
 {
-  local index_file name this_file
+  #local index_file name this_file
 
   index_file="$1"
   this_file=`echo $2 | sed 's,.*/,,' | sed 's,\..*$,,'`
