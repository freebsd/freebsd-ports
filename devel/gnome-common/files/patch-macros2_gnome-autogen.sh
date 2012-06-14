From 1fed4ee7015b89a1ac4c4a535aeb753e820e4970 Mon Sep 17 00:00:00 2001
From: Xiao-Long Chen <chenxiaolong@cxl.epac.to>
Date: Sun, 29 Apr 2012 17:44:32 +0000
Subject: Add support for automake 1.12

Bug #675093.
---
diff --git a/macros2/gnome-autogen.sh b/macros2/gnome-autogen.sh
index 9967f89..3179c3f 100644
--- macros2/gnome-autogen.sh
+++ macros2/gnome-autogen.sh
@@ -325,13 +325,14 @@ AUTOHEADER=`echo $AUTOCONF | sed s/autoconf/autoheader/`
 
 case $REQUIRED_AUTOMAKE_VERSION in
     1.4*) automake_progs="automake-1.4" ;;
-    1.5*) automake_progs="automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
-    1.6*) automake_progs="automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
-    1.7*) automake_progs="automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
-    1.8*) automake_progs="automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
-    1.9*) automake_progs="automake-1.11 automake-1.10 automake-1.9" ;;
-    1.10*) automake_progs="automake-1.11 automake-1.10" ;;
-    1.11*) automake_progs="automake-1.11" ;;
+    1.5*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
+    1.6*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
+    1.7*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
+    1.8*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
+    1.9*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9" ;;
+    1.10*) automake_progs="automake-1.12 automake-1.11 automake-1.10" ;;
+    1.11*) automake_progs="automake-1.12 automake-1.11" ;;
+    1.12*) automake_progs="automake-1.12" ;;
 esac
 version_check automake AUTOMAKE "$automake_progs" $REQUIRED_AUTOMAKE_VERSION \
     "http://ftp.gnu.org/pub/gnu/automake/automake-$REQUIRED_AUTOMAKE_VERSION.tar.gz"
--
cgit v0.9.0.2
