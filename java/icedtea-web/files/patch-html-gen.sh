--- html-gen.sh.orig	2016-02-03 13:47:43 UTC
+++ html-gen.sh
@@ -74,7 +74,7 @@ else
     unset REPO_URL
 fi
 
-start_time="$(date +%s.%N)"
+start_time="$(date +%s)"
 
 if [ ! -e html-gen ]; then
 	echo "No html-gen directory, exiting. See Makefile.am for usage"
@@ -168,7 +168,7 @@ done
 
 sed -i -r 's|(\*\ .*):|<u>\1</u>:|' ChangeLog.html # Underline changed files in ChangeLog, eg "* Makefile.am:"
 
-end_time="$(date +%s.%N)"
+end_time="$(date +%s)"
 
 print_debug "HTML generation complete"
 print_debug "Total elapsed time: $(echo "$end_time - $start_time" | bc )"
