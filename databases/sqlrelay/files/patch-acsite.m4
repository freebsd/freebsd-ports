--- acsite.m4.orig	2013-09-21 13:33:47.000000000 +0200
+++ acsite.m4	2013-10-28 19:18:27.846799325 +0100
@@ -680,6 +680,7 @@
 	AC_MSG_RESULT(no)
 fi
 
+if ( test -z "$PTHREADINCLUDES" -a -z "$PTHREADLIBS" ); then
 HAVE_PTHREAD=""
 PTHREADINCLUDES=""
 PTHREADLIB=""
@@ -808,7 +809,9 @@
 		fi
 	done
 fi
-
+else
+	HAVE_PTHREAD="yes"
+fi
 FW_INCLUDES(pthreads,[$PTHREADINCLUDES])
 FW_LIBS(pthreads,[$PTHREADLIB])
 
