--- ltmain.sh.orig	Wed Jul  2 16:56:39 2003
+++ ltmain.sh	Wed Jul  2 16:58:03 2003
@@ -1279,3 +1279,3 @@
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
