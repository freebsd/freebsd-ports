--- Lib/asu-main.sh	Thu Oct 18 16:33:54 2001
+++ Lib/asu-main.sh	Thu Oct 18 16:35:01 2001
@@ -8,6 +8,8 @@
 #
 # Copyright (C) 2001 abfackeln@abfackeln.com
 # 
+# FreeBSD modifications by matuska@wu-wien.ac.at
+# 
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
 # as published by the Free Software Foundation; either version 2
@@ -32,9 +34,9 @@
 Install_Package ()
 {
    if [ -f "$PATCH_DIR/$1-patch.tar.gz" ]; then
-      pushd $UT_DIR > /dev/null
+      /bin/csh -c pushd $UT_DIR > /dev/null 2> /dev/null
       tar zxpf "$PATCH_DIR/$1-patch.tar.gz"
-      popd > /dev/null
+      /bin/csh -c popd > /dev/null 2> /dev/null
       if [ -f "$UT_DIR/$1-install.asu" ]; then
          TMP=`head -1 "$UT_DIR/$1-install.asu" | sed -n -e "s/#~asu \([0-9.]*\).*$/\\\\1/" -e "t label" -e "d" -e ": label" -e "p"`
          if [ -f "$ABF_DIR/legacy-asu-script-$TMP.sh" ]; then
@@ -1545,9 +1547,9 @@
    echo
    echo "Zip and Umod files in your game directory:"
    echo
-   pushd $UT_DIR > /dev/null
+   /bin/csh -c pushd $UT_DIR > /dev/null 2> /dev/null
    ls *.[zZ][iI][pP] *.[uU][mM][oO][dD] 2> /dev/null
-   popd > /dev/null
+   /bin/csh -c popd > /dev/null 2> /dev/null
    echo
    echo "Enter the name of the file from the above list"
    echo "or enter the full file name if it is located elsewhere."
--- Lib/legacy-asu-script-0.1.sh	Sat Jun 23 02:46:49 2001
+++ Lib/legacy-asu-script-0.1.sh	Thu Oct 18 18:01:54 2001
@@ -1,10 +1,29 @@
 #~asu 0.4
 #~legacy 0.1 ## compatability functions for version 0.1 scripts
 
-AddIni () { IniAdd "$1" "$2" "$3" "$4" }
-UnAddIni () { IniUnAdd "$1" "$2" "$3" "$4" }
-SetIni () { IniSet "$1" "$2" "$3" "$4" }
-UnSetIni () { IniUnSet "$1" "$2" "$3" }
-MatchIni () { IniMatch "$1" "$2" "$3" "$4" }
-ReadIni () { IniRead "$1" "$2" "$3" }
+AddIni() 
+{
+	IniAdd "$1" "$2" "$3" "$4"
+}
 
+UnAddIni() {
+IniUnAdd "$1" "$2" "$3" "$4"
+}
+
+SetIni() 
+{
+IniSet "$1" "$2" "$3" "$4"
+}
+
+UnSetIni() 
+{
+IniUnSet "$1" "$2" "$3"
+}
+
+MatchIni() {
+IniMatch "$1" "$2" "$3" "$4"
+}
+
+ReadIni() {
+IniRead "$1" "$2" "$3"
+}
