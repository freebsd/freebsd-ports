--- plot/plot.sh.orig	2019-02-09 03:42:21 UTC
+++ plot/plot.sh
@@ -3,6 +3,8 @@ case $1 in
 PATH=/bin:/usr/bin:/usr/local/bin:/usr/local/libexec:/usr/libexec
 
 case $1 in
+-T)	t=-T$2
+	shift; shift;;
 -T*)	t=$1
 	shift ;;
 *)	t=-T$TERM
