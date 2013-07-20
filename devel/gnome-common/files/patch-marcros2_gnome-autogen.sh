--- macros2/gnome-autogen.sh.orig	2012-10-16 00:58:19.000000000 +0200
+++ macros2/gnome-autogen.sh	2013-07-20 22:13:10.000000000 +0200
@@ -346,14 +346,16 @@
 
 case $REQUIRED_AUTOMAKE_VERSION in
     1.4*) automake_progs="automake-1.4" ;;
-    1.5*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
-    1.6*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
-    1.7*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
-    1.8*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
-    1.9*) automake_progs="automake-1.12 automake-1.11 automake-1.10 automake-1.9" ;;
-    1.10*) automake_progs="automake-1.12 automake-1.11 automake-1.10" ;;
-    1.11*) automake_progs="automake-1.12 automake-1.11" ;;
-    1.12*) automake_progs="automake-1.12" ;;
+    1.5*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6 automake-1.5" ;;
+    1.6*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7 automake-1.6" ;;
+    1.7*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8 automake-1.7" ;;
+    1.8*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9 automake-1.8" ;;
+    1.9*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10 automake-1.9" ;;
+    1.10*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11 automake-1.10" ;;
+    1.11*) automake_progs="automake-1.14 automake-1.13 automake-1.12 automake-1.11" ;;
+    1.12*) automake_progs="automake-1.14 automake-1.13 automake-1.12" ;;
+    1.13*) automake_progs="automake-1.14 automake-1.13" ;;
+    1.14*) automake_progs="automake-1.14" ;;
 esac
 version_check automake AUTOMAKE "$automake_progs" $REQUIRED_AUTOMAKE_VERSION \
     "http://ftp.gnu.org/pub/gnu/automake/automake-$REQUIRED_AUTOMAKE_VERSION.tar.gz"
@@ -426,6 +428,14 @@
 	printbold "Processing $configure_ac"
 	cd $dirname
 
+	# if the AC_CONFIG_MACRO_DIR() macro is used, create that directory
+	# This is a automake bug fixed in automake 1.13.2
+	# See http://debbugs.gnu.org/cgi/bugreport.cgi?bug=13514
+	m4dir=`autoconf --trace AC_CONFIG_MACRO_DIR | sed 's,^.*:,,g'`
+	if [ -n "$m4dir" ]; then
+	    mkdir -p $m4dir
+	fi
+
         # Note that the order these tools are called should match what
         # autoconf's "autoupdate" package does.  See bug 138584 for
         # details.
