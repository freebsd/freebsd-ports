--- autogen.sh.orig	Fri Mar 17 22:07:40 2006
+++ autogen.sh	Fri Mar 17 16:52:53 2006
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
 
