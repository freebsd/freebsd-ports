--- ../setup2/script/setup.sh.orig	Mon Jun  9 07:49:10 2003
+++ ../setup2/script/setup.sh	Mon Jun  9 07:49:56 2003
@@ -118,6 +118,16 @@
 	 LD_LIBRARY_PATH=${sd_archive_path}:.
 	 export LD_LIBRARY_PATH
 	 ;;
+  FreeBSD)
+     # @@@ <NOTE> @@@
+     # Please remove '.' as soon as all to be registered UNO components...
+     # 1) link with a runpath of '$ORIGIN', and
+     # 2) link against 'libcppuhelper$(COMID).so.$(UDK_MAJOR)'
+     #    instead of obsolete 'libcppuhelper$(UDK_MAJOR)$(COMID).so'
+     # @@@ </NOTE> @@@
+	 LD_LIBRARY_PATH=${sd_archive_path}:.
+	 export LD_LIBRARY_PATH
+	 ;;
   IRIX*)
 	 LD_LIBRARYN32_PATH=${sd_archive_path}
 	 export LD_LIBRARYN32_PATH
