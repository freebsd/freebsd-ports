--- config.sh.orig	Thu Feb  9 09:25:34 1995
+++ config.sh	Sat Jun 14 07:50:30 2003
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
@@ -50,4 +29,4 @@
     MKTIME="mktime.o"
   fi
 fi
-echo CC=${CC} MKTIME=${MKTIME} FLAG1=${FMKTIME} FLAG2=${FUTIME} OPTS="${OPTS}" >$template
+echo MKTIME=${MKTIME} FLAG1=${FMKTIME} FLAG2=${FUTIME} OPTS="${OPTS}" >$template
