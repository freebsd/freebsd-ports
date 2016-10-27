--- make.sh.orig	2016-08-08 07:17:50 UTC
+++ make.sh
@@ -1,58 +1,19 @@
-tmp_src_filename=fdfs_check_bits.c
-cat <<EOF > $tmp_src_filename
-#include <stdio.h>
-#include <unistd.h>
-#include <fcntl.h>
-int main()
-{
-	printf("%d\n", (int)sizeof(long));
-	printf("%d\n", (int)sizeof(off_t));
-	return 0;
-}
-EOF
-
-gcc -D_FILE_OFFSET_BITS=64 -o a.out $tmp_src_filename
-output=$(./a.out)
 
-if [ -f /bin/expr ]; then
-  EXPR=/bin/expr
-else
-  EXPR=/usr/bin/expr
-fi
-
-count=0
-int_bytes=4
-off_bytes=8
-for col in $output; do
-    if [ $count -eq 0 ]; then
-        int_bytes=$col
-    else
-        off_bytes=$col
-    fi
-
-    count=$($EXPR $count + 1)
-done
-
-/bin/rm -f a.out $tmp_src_filename
-if [ "$int_bytes" -eq 8 ]; then
+if [ "$(/usr/bin/uname -m)" = "amd64"  ]; then
  OS_BITS=64
-else
- OS_BITS=32
-fi
-
-if [ "$off_bytes" -eq 8 ]; then
  OFF_BITS=64
 else
+ OS_BITS=32
  OFF_BITS=32
 fi
 
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
 
@@ -74,7 +35,7 @@ if [ "$uname" = "Linux" ]; then
   fi
   CFLAGS="$CFLAGS"
 elif [ "$uname" = "FreeBSD" ] || [ "$uname" = "Darwin" ]; then
-  LIBS="$LIBS -L/usr/lib"
+  LIBS="$LIBS -L/usr/local/lib"
   CFLAGS="$CFLAGS"
   if [ "$uname" = "Darwin" ]; then
     CFLAGS="$CFLAGS -DDARWIN"
@@ -180,26 +141,3 @@ perl -pi -e "s#\\\$\(LIBS\)#$LIBS#g" Mak
 perl -pi -e "s#\\\$\(TARGET_PREFIX\)#$TARGET_PREFIX#g" Makefile
 cd ..
 
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
