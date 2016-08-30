--- qb/qb.params.sh.orig	2016-07-15 20:24:15 UTC
+++ qb/qb.params.sh
@@ -79,7 +79,10 @@ parse_input() # Parse stuff :V
 				opt_exists "${arg%%=*}" "$1"
 				eval "$opt=\"$val\""
 			;;
-			-h|--help) print_help; exit 0;;
+			--x-*)
+			;;
+			--build*)
+			;;
 			*) echo "Unknown option $1"; exit 1;;
 		esac
 		shift
