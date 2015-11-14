--- qb/qb.params.sh.orig	2015-07-19 09:50:27 UTC
+++ qb/qb.params.sh
@@ -59,6 +59,9 @@ parse_input() # Parse stuff :V
 	while [ "$1" ]; do
 		case "$1" in
 			--prefix=*) PREFIX=${1##--prefix=};;
+			--build=*) ;;
+			--x-includes=*) ;;
+			--x-libraries=*) ;;
 			--global-config-dir=*) GLOBAL_CONFIG_DIR=${1##--global-config-dir=};;
 			--host=*) CROSS_COMPILE=${1##--host=}-;;
 			--enable-*)
