--- Global.cc.orig	2010-09-14 16:49:16.000000000 +0200
+++ Global.cc	2010-09-14 16:50:18.000000000 +0200
@@ -203,7 +203,7 @@
 #ifdef UseLocalFiles
   static const char confFile[] = "xtide.conf";
 #else
-  static const char confFile[] = "/etc/xtide.conf";
+  static const char confFile[] = "%%PREFIX%%/etc/xtide.conf";
 #endif
   static bool firstCall (true);
   static SafeVector<Dstr> xtideConfLines (2U);
@@ -390,10 +390,10 @@
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
