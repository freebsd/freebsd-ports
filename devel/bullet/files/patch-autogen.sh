--- autogen.sh.orig	2008-03-27 23:45:16.000000000 -0500
+++ autogen.sh	2008-03-27 23:45:45.000000000 -0500
@@ -13,11 +13,11 @@
   cat $i >> $MACROFILE
 done
 
-autoheader
+%%AUTOHEADER%%
 rc=$?
 
 if test $rc -eq 0; then
-  autoconf
+  %%AUTOCONF%%
   rc=$?
 fi
 
