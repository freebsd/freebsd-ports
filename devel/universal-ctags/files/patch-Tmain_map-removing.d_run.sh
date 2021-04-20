--- Tmain/map-removing.d/run.sh.orig	2021-04-18 04:45:23 UTC
+++ Tmain/map-removing.d/run.sh
@@ -6,25 +6,25 @@ CTAGS=$1
 echo default map including '*.m'
 echo =======================================
 ${CTAGS} --quiet --options=NONE \
-	 --list-maps | grep '\*\.m\>.*$'
+	 --list-maps | grep '\*\.m\>'
 echo
 
 echo '[--map-<LANG>]' removing from '*.m' from 'ObjectiveC'
 echo =======================================
 ${CTAGS} --quiet --options=NONE \
-	 --map-ObjectiveC=-.m --list-maps | grep '\*\.m\>.*$'
+	 --map-ObjectiveC=-.m --list-maps | grep '\*\.m\>'
 echo
 
 echo '[--map-<LANG>]' adding '*.m' to 'Ada'
 echo =======================================
 ${CTAGS} --quiet --options=NONE \
-	 --map-Ada=+.m --list-maps | grep '\*\.m\>.*$'
+	 --map-Ada=+.m --list-maps | grep '\*\.m\>'
 echo
 
 echo '[--map-<LANG>]' removing from '*.m' from 'ObjectiveC', and adding '*.m' to 'Ada'
 echo =======================================
 ${CTAGS} --quiet --options=NONE \
-	 --map-ObjectiveC=-.m --map-Ada=+.m --list-maps | grep '\*\.m\>.*$'
+	 --map-ObjectiveC=-.m --map-Ada=+.m --list-maps | grep '\*\.m\>'
 echo
 
 echo '[--map-<LANG>]' guessing parser with adding '*.m' to 'Ada'
