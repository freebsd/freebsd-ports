--- runtests.sh~	Tue Jan  8 12:58:39 2002
+++ runtests.sh	Tue Jan  8 12:58:47 2002
@@ -9,4 +9,4 @@
   fi
 done
 
-/usr/bonsaitools/bin/perl -e "${PART1}${TEST_VERBOSE}${PART2}" t/*.t
+/usr/bin/perl -e "${PART1}${TEST_VERBOSE}${PART2}" t/*.t
