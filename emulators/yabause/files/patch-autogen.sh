--- autogen.sh.orig	2012-03-25 20:41:13.000000000 -0500
+++ autogen.sh	2012-03-25 20:42:38.000000000 -0500
@@ -1,2 +1,2 @@
-aclocal && autoconf && automake --add-missing --copy
-cd src/c68k && aclocal && autoconf && automake
+%%ACLOCAL%% && %%AUTOCONF%% && %%AUTOMAKE%% --add-missing --copy
+cd src/c68k && %%ACLOCAL%% && %%AUTOCONF%% && %%AUTOMAKE%%
