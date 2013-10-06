--- src/conf.sh.orig	1995-06-15 23:19:24.000000000 -0700
+++ src/conf.sh	2013-10-05 20:29:37.323219649 -0700
@@ -73,17 +73,6 @@
 	ech='echo -n' dots='... '
 esac
 
-$ech >&3 "$0: testing permissions $dots"
-rm -f a.d &&
-date >a.d &&
-chmod 0 a.d &&
-{ test -w a.d || cp /dev/null a.d 2>/dev/null; } && {
-	echo >&3 "$n$0: This command should not be run with superuser permissions."
-	exit 1
-}
-echo >&3 OK
-rm -f a.d || exit
-
 $ech >&3 "$0: testing compiler for plausibility $dots"
 echo 'main() { return 0; }' >a.c
 rm -f a.exe a.out || exit
