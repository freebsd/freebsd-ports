--- acsite.m4.orig	Thu Aug  5 10:04:21 2004
+++ acsite.m4	Sat Sep 11 21:58:33 2004
@@ -396,7 +396,7 @@
 dnl sets the substitution variable PTHREADLIBS
 AC_DEFUN([FW_CHECK_PTHREAD],
 [
-
+if ( test -z "$PTHREADINCLUDES" -a -z "$PTHREADLIBS" ); then
 HAVE_PTHREAD=""
 PTHREADINCLUDES=""
 PTHREADLIBS=""
@@ -440,7 +440,9 @@
 		PTHREADLIBS="-pthread"
 	fi
 fi
-
+else
+	HAVE_PTHREAD="yes"
+fi
 FW_INCLUDES(pthreads,[$PTHREADINCLUDES])
 FW_LIBS(pthreads,[$PTHREADLIBS])
 
@@ -2149,13 +2151,7 @@
 			FW_CHECK_FILE("$JAVAPATH/include/jni.h",[JAVAINCLUDES=\"-I$JAVAPATH/include\"])
 			if ( test -n "$JAVAINCLUDES" )
 			then
-				for i in `ls -d $JAVAPATH/include/*`
-				do
-					if ( test -d "$i" )
-					then
-						JAVAINCLUDES="$JAVAINCLUDES -I$i"
-					fi
-				done
+				JAVAINCLUDES="$JAVAINCLUDES -I`dirname $JAVAPATH/include/*/jni_md.h`"
 			fi
 		fi
 		
