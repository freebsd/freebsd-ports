
$FreeBSD$

--- formats/index_html.sh	2001/08/21 13:34:31	1.1
+++ formats/index_html.sh	2001/08/21 13:36:00
@@ -1,8 +1,8 @@
 #!/bin/sh
 
-function make_targets_file
+make_targets_file()
 {
-  local file line line_nr error targets_file files
+  #local file line line_nr error targets_file files
 
   targets_file="$1"
   shift
