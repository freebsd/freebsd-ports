--- Scripts/buildUnix.sh.orig	Wed Feb  4 09:16:35 2004
+++ Scripts/buildUnix.sh	Wed Feb  4 09:17:32 2004
@@ -28,11 +28,11 @@
 
 # create the build system for libquesa
 ######################################
-aclocal
-automake --add-missing
-automake
-autoconf
-./configure
+%%ACLOCAL%%
+%%SETENV%% %%AUTOMAKE_ENV%% %%AUTOMAKE%% --add-missing
+%%SETENV%% %%AUTOMAKE_ENV%% %%AUTOMAKE%% -i
+%%SETENV%% %%AUTOCONF_ENV%% %%AUTOCONF%%
+#./configure
 
 # create the build system for the examples
 ######################################
@@ -40,27 +40,25 @@
 pushd Examples || exit
 
 # make sure we can find gtk-config
-PATH=${PATH}:/usr/local/bin
-
-export PATH
+#setenv PATH ${PATH}:/usr/local/bin
 
 # make sure we can find gtk.m4
-ACLOCALADDPATHS=
-if test -d /usr/local/share/aclocal; then
- ACLOCALADDPATHS="${ACLOCALADDPATHS} -I /usr/local/share/aclocal"
-fi
+#ACLOCALADDPATHS=
+#if test -d /usr/local/share/aclocal; then
+# ACLOCALADDPATHS="${ACLOCALADDPATHS} -I /usr/local/share/aclocal"
+#fi
 
-aclocal ${ACLOCALADDPATHS}
-automake --add-missing
-automake
-autoconf
-./configure
+%%ACLOCAL%%
+%%SETENV%% %%AUTOMAKE_ENV%% %%AUTOMAKE%% --add-missing
+%%SETENV%% %%AUTOMAKE_ENV%% %%AUTOMAKE%% -i
+%%SETENV%% %%AUTOCONF_ENV%% %%AUTOCONF%%
+#./configure
 
 popd
 
 # build libquesa
 ######################################
-make
+#make
 
 popd
 
