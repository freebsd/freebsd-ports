--- config.sh.orig	Fri Jun 13 14:14:53 2003
+++ config.sh	Fri Jun 13 14:15:18 2003
@@ -8,27 +8,6 @@
   exit
 fi
 
-# check compiler
-CC=cc
-#type
-#if [ $? = 1 ]; then
-  # Ultrix
-  for file in `echo $PATH|sed 's/:/ /g'`
-  do
-    if [ -f $file/gcc ]; then
-      CC=gcc
-      OPTS=-g
-      break
-    fi
-  done
-#else
-#  set `type gcc`
-#  if [ $1 = gcc ]; then
-#    CC=$3
-#    OPTS=-g
-#  fi
-#fi
-
 if [ -f /usr/include/utime.h ]; then
     FUTIME="-DHAME_UTIME_H"
 fi
