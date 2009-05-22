--- config/m4/oracle.m4.orig	2008-05-14 19:07:34.000000000 +0200
+++ config/m4/oracle.m4	2009-05-07 19:15:56.463399933 +0200
@@ -113,6 +113,11 @@
         ora_cflags="$ora_cflags -I$dir"
         echo "adding -I$dir" >&AS_MESSAGE_LOG_FD()
       fi
+      echo "trying ociextp.h $dir/ociextp.h" >&AS_MESSAGE_LOG_FD()
+      if test -r $dir/ociextp.h; then
+        ora_cflags="$ora_cflags -I$dir"
+        echo "adding -I$dir" >&AS_MESSAGE_LOG_FD()
+      fi
     done
 
     ora_check_lib="
