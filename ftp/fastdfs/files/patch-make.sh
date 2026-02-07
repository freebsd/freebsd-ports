--- make.sh.orig	2019-12-30 23:36:03 UTC
+++ make.sh
@@ -1,10 +1,10 @@
 ENABLE_STATIC_LIB=0
 ENABLE_SHARED_LIB=1
-TARGET_PREFIX=$DESTDIR/usr
-TARGET_CONF_PATH=$DESTDIR/etc/fdfs
+TARGET_PREFIX=$DESTDIR$PREFIX
+TARGET_CONF_PATH=$DESTDIR$PREFIX/etc/fdfs
 TARGET_INIT_PATH=$DESTDIR/etc/init.d
 
-WITH_LINUX_SERVICE=1
+WITH_LINUX_SERVICE=0
 
 DEBUG_FLAG=1
 
@@ -25,15 +25,7 @@ fi
 
 uname=$(uname)
 
-if [ "$OS_BITS" -eq 64 ]; then
-  if [ "$uname" = "Darwin" ]; then
-    LIB_VERSION=lib
-  else
-    LIB_VERSION=lib64
-  fi
-else
-  LIB_VERSION=lib
-fi
+LIB_VERSION=lib
 
 LIBS=''
 
@@ -46,7 +38,7 @@ if [ "$uname" = "Linux" ]; then
   fi
   CFLAGS="$CFLAGS"
 elif [ "$uname" = "FreeBSD" ] || [ "$uname" = "Darwin" ]; then
-  LIBS="$LIBS -L/usr/lib"
+  LIBS="$LIBS -L$PREFIX/lib"
   CFLAGS="$CFLAGS"
   if [ "$uname" = "Darwin" ]; then
     CFLAGS="$CFLAGS -DDARWIN"
@@ -153,29 +145,3 @@ perl -pi -e "s#\\\$\(CFLAGS\)#$CFLAGS#g"
 perl -pi -e "s#\\\$\(LIBS\)#$LIBS#g" Makefile
 perl -pi -e "s#\\\$\(TARGET_PREFIX\)#$TARGET_PREFIX#g" Makefile
 cd ..
-
-if [ "$1" = "install" ]; then
-  cd ..
-  cp -f restart.sh $TARGET_PREFIX/bin
-  cp -f stop.sh $TARGET_PREFIX/bin
-
-  if [ "$uname" = "Linux" ]; then
-    if [ "$WITH_LINUX_SERVICE" = "1" ]; then
-      if [ ! -d /etc/fdfs ]; then
-        mkdir -p /etc/fdfs
-        cp -f conf/tracker.conf $TARGET_CONF_PATH/tracker.conf.sample
-        cp -f conf/storage.conf $TARGET_CONF_PATH/storage.conf.sample
-        cp -f conf/client.conf $TARGET_CONF_PATH/client.conf.sample
-        cp -f conf/storage_ids.conf $TARGET_CONF_PATH/storage_ids.conf.sample
-        cp -f conf/http.conf $TARGET_CONF_PATH/http.conf.sample
-        cp -f conf/mime.types $TARGET_CONF_PATH/mime.types.sample
-      fi
-      mkdir -p $TARGET_INIT_PATH
-      cp -f init.d/fdfs_trackerd $TARGET_INIT_PATH
-      cp -f init.d/fdfs_storaged $TARGET_INIT_PATH
-#      /sbin/chkconfig --add fdfs_trackerd 
-#      /sbin/chkconfig --add fdfs_storaged
-    fi
-  fi
-fi
-
