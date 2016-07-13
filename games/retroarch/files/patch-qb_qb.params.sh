--- qb/qb.params.sh.orig	2016-05-02 20:17:12 UTC
+++ qb/qb.params.sh
@@ -63,6 +63,9 @@ parse_input() # Parse stuff :V
 	while [ "$1" ]; do
 		case "$1" in
 			--prefix=*) PREFIX=${1##--prefix=};;
+			--build=*) ;;
+			--x-includes=*) ;;
+			--x-libraries=*) ;;
 			--global-config-dir=*) GLOBAL_CONFIG_DIR=${1##--global-config-dir=};;
 			--host=*) CROSS_COMPILE=${1##--host=}-;;
 			--enable-*)
