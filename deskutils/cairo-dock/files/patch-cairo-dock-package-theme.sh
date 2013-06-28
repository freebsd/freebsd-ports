--- ./data/scripts/cairo-dock-package-theme.sh.orig	2013-03-23 17:55:12.000000000 +0200
+++ ./data/scripts/cairo-dock-package-theme.sh	2013-06-27 18:03:18.000000000 +0300
@@ -125,7 +125,7 @@
 	if test "x${theme}" != "x"; then
 		#\__________ On cherche si ce theme est un theme officiel ou non.
 		echo "un theme est present ($theme)"
-		wget "$THEME_SERVER/$3/list.conf" -O "liste.tmp" -t 3 -T 30
+		fetch -o "liste.tmp" -T 30 "$THEME_SERVER/$3/list.conf"
 		if test -f "liste.tmp" ; then
 			grep "^\[${theme}\]" "liste.tmp"
 			if test "$?" != "0" -a  "$theme" != "Classic" -a "$theme" != "default"; then  # pas un theme officiel
