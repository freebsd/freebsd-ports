--- Global.cc.orig	Thu Mar 15 09:58:01 2007
+++ Global.cc	Fri Mar 23 02:31:17 2007
@@ -241,10 +241,10 @@
     break;
   case Error::NO_HFILE_PATH:
     text_out += "NO_HFILE_PATH\n\
-If /etc/xtide.conf is not provided, you must set the environment variable\n\
+If %%PREFIX%%/etc/xtide.conf is not provided, you must set the environment variable\n\
 HFILE_PATH to point to your harmonics files.  Example:\n\
   export HFILE_PATH=/usr/local/share/xtide/harmonics.tcd\n\
-Please refer to the documentation for usage of /etc/xtide.conf.";
+Please refer to the documentation for usage of %%PREFIX%%/etc/xtide.conf.";
     break;
   case Error::NO_HFILE_IN_PATH:
     text_out += "NO_HFILE_IN_PATH\n\
