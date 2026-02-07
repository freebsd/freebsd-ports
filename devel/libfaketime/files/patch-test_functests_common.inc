--- test/functests/common.inc.orig	2016-10-28 11:24:53 UTC
+++ test/functests/common.inc
@@ -8,7 +8,8 @@ platform()
 	case "$out" in
 	*Darwin*) echo "mac" ;;
 	*Linux*) echo "linuxlike" ;;
-    GNU|GNU/kFreeBSD) echo "linuxlike" ;;
+	GNU|GNU/kFreeBSD) echo "linuxlike" ;;
+	*FreeBSD*) echo "linuxlike" ;;
         *SunOS*) echo "sunos" ;;
 	*) echo 1>&2 unsupported platform, uname=\"$out\" ;;
 	esac
