Index: src/lib/apis/posix/limits.h
===================================================================
RCS file: /usr/home/stefan/tendra/cvsup/tendra/src/lib/apis/posix/limits.h,v
retrieving revision 1.1
diff -c -u -r1.1 limits.h
--- src/lib/apis/posix/limits.h	26 Jan 2002 21:31:34 -0000	1.1
+++ src/lib/apis/posix/limits.h	17 Feb 2003 14:54:23 -0000
@@ -28,14 +28,14 @@
 +IMPLEMENT "ansi", "limits.h" ;
 
 +DEFINE _POSIX_ARG_MAX 4096 ;
-+DEFINE _POSIX_CHILD_MAX 6 ;
++CONST int _POSIX_CHILD_MAX ;
 +DEFINE _POSIX_LINK_MAX 8 ;
 +DEFINE _POSIX_MAX_CANON 255 ;
 +DEFINE _POSIX_MAX_INPUT 255 ;
 +DEFINE _POSIX_NAME_MAX 14 ;
-+DEFINE _POSIX_NGROUPS_MAX 0 ;
-+DEFINE _POSIX_OPEN_MAX 16 ;
-+DEFINE _POSIX_PATH_MAX 255 ;
++CONST int _POSIX_NGROUPS_MAX ;
++CONST int _POSIX_OPEN_MAX ;
++CONST int _POSIX_PATH_MAX ;
 +DEFINE _POSIX_PIPE_BUF 512 ;
 
 +CONST int NGROUPS_MAX ;
