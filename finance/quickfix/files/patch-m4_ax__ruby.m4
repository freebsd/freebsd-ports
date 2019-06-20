--- m4/ax_ruby.m4.orig	2018-04-16 02:40:31 UTC
+++ m4/ax_ruby.m4
@@ -2,7 +2,7 @@ AC_DEFUN([AX_RUBY],
 [
 RUBY=${RUBY:-"ruby"}
 
-RUBY_PREFIX=[`$RUBY -e 'require "rbconfig"; print Config::CONFIG["archdir"], "\n"'`]
+RUBY_PREFIX=[`$RUBY -e 'require "rbconfig"; print RbConfig::CONFIG["archdir"], "\n"'`]
 AC_SUBST(RUBY_PREFIX)
 
 has_ruby=false
@@ -21,7 +21,7 @@ if test $has_ruby = true
 then
     RUBY_CFLAGS="-I${RUBY_PREFIX}" 
     AC_SUBST(RUBY_CFLAGS)
-    RUBY_SITE_PACKAGES=[`ruby -e 'require "rbconfig"; print Config::CONFIG["sitedir"], "\n"'`]
+    RUBY_SITE_PACKAGES=[`ruby -e 'require "rbconfig"; print RbConfig::CONFIG["sitearchdir"], "\n"'`]
     AC_SUBST(RUBY_SITE_PACKAGES)
     AC_DEFINE(HAVE_RUBY, 1, Define if you have ruby)
 fi
