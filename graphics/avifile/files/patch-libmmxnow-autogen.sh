--- libmmxnow/autogen.sh.orig	Thu Jan 10 23:27:57 2002
+++ libmmxnow/autogen.sh	Thu Jan 10 23:28:06 2002
@@ -8,8 +8,8 @@
 
 # Debian unstable allows to have several different versions of autoconf
 # in the one system
-use_autoconf=autoconf
-use_autoheader=autoheader
+use_autoconf=autoconf213
+use_autoheader=autoheader213
 use_copy="--copy"
 ( which autoconf2.50 2>/dev/null | grep -q "^/" ) && use_autoconf=autoconf2.50
 ( which autoheader2.50 2>/dev/null | grep -q "^/" ) && use_autoheader=autoheader2.50
