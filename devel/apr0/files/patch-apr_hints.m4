--- apr-0.9.4/build/apr_hints.m4.orig	Sun Nov  2 01:23:53 2003
+++ apr-0.9.4/build/apr_hints.m4	Sun Nov  2 01:24:44 2003
@@ -135,9 +135,7 @@
 		APR_ADDTO(CFLAGS, [-funsigned-char])
 		;;
 	esac
-	APR_SETIFNULL(enable_threads, [no])
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-	APR_ADDTO(CPPFLAGS, [-D_REENTRANT -D_THREAD_SAFE])
 	;;
     *-next-nextstep*)
 	APR_SETIFNULL(CFLAGS, [-O])
