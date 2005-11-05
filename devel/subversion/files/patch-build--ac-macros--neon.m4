--- build/ac-macros/neon.m4.orig	Sat Nov  5 16:12:58 2005
+++ build/ac-macros/neon.m4	Sat Nov  5 16:13:14 2005
@@ -1,4 +1,4 @@
-dnl   SVN_LIB_NEON(wanted_regex, latest_working_ver, url)
+                       dnl   SVN_LIB_NEON(wanted_regex, latest_working_ver, url)
 dnl
 dnl   Search for a suitable version of neon.  wanted_regex is a
 dnl   regular expression used in a Bourne shell switch/case statement
@@ -132,7 +132,7 @@
         if test "$NEON_VERSION" = "$svn_allowed_neon" -o $svn_allowed_neon = "any"; then
             svn_allowed_neon_on_system="yes"
             SVN_NEON_INCLUDES=[`$neon_config --cflags | sed -e 's/-D[^ ]*//g'`]
-            NEON_LIBS=`$neon_config --la-file`
+            NEON_LIBS=`$neon_config --libs`
             CFLAGS=["$CFLAGS `$neon_config --cflags | sed -e 's/-I[^ ]*//g'`"]
             svn_lib_neon="yes"
             break
