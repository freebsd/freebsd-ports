--- config/version.sh.orig	2001-04-03 06:14:41 UTC
+++ config/version.sh
@@ -36,7 +36,7 @@ do
     fi
 done
 
-IFS=" "
+IFS="$OFS"
 
 if test "${LANG+set}" = set; then LANG=C; export LANG; fi
 if test "${LC_ALL+set}" = set; then LC_ALL=C; export LC_ALL; fi
