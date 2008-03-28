--- autogen.sh.orig	Thu Dec  1 09:52:33 2005
+++ autogen.sh	Thu Dec  1 09:53:14 2005
@@ -8,11 +8,11 @@
 
 echo "aclocal..."
 #autoheader
-aclocal -I mk/autoconf
+%%ACLOCAL%% -I mk/autoconf
 
 # generate Jamconfig.in
 echo "generating Jamconfig.in ..."
-autoconf --trace=AC_SUBST \
+%%AUTOCONF%% --trace=AC_SUBST \
   | sed -e 's/configure.ac:[0-9]*:AC_SUBST:\([^:]*\).*/\1 ?= "@\1@" ;/g' \
   > Jamconfig.in
 sed -e 's/.*BACKSLASH.*//' -i~ Jamconfig.in
@@ -21,7 +21,7 @@
 echo 'JAMCONFIG_READ = yes ;' >> Jamconfig.in
 
 echo "autoconf"
-autoconf
+%%AUTOCONF%%
 
 # create symlinks to the source dirs
 echo "Updating Source symlinks..."
