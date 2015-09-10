--- config/m4/oracle.m4.orig	2009-10-23 16:19:57 UTC
+++ config/m4/oracle.m4
@@ -113,6 +113,11 @@ Please install the instant client sdk pa
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
