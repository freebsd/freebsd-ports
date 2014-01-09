--- spec-sfs2008/post_install.sh.orig	2013-09-23 14:24:56.000000000 -0700
+++ spec-sfs2008/post_install.sh	2013-09-23 14:25:16.000000000 -0700
@@ -19,7 +19,7 @@
 #
 # Fix up the binaries
 #
-for i in binaries/*
+for i in binaries/* bin
 do
         if [ -f $i/sfsnfs3 ]; then
            chmod 755 $i/sfs*
