--- ./acsite.m4.orig	Thu Aug  5 08:04:21 2004
+++ ./acsite.m4	Sat Dec 11 22:01:02 2004
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
 
