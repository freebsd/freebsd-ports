--- unix/fcitx/gen_fcitx_mozc_i18n.sh.orig	1970-01-01 09:00:00.000000000 +0900
+++ unix/fcitx/gen_fcitx_mozc_i18n.sh	2012-05-22 13:46:54.090828960 +0900
@@ -0,0 +1,11 @@
+#!/bin/sh
+objdir="$1"
+
+cd po || exit 1
+
+mkdir -p "$1"
+
+for pofile in *.po
+do
+  msgfmt "$pofile" -o "$1/${pofile%po}mo"
+done
