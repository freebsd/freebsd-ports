--- src/conf.sh.orig	1995-06-16 06:19:24 UTC
+++ src/conf.sh
@@ -43,7 +43,7 @@ Id='$Id: conf.sh,v 5.25 1995/06/16 06:19:24 eggert Exp
 : ${DIFF_L=1}
 : ${DIFF_SUCCESS=0} ${DIFF_FAILURE=1} ${DIFF_TROUBLE=2}
 : ${ED=/bin/ed}
-: ${SENDMAIL='"/usr/lib/sendmail"'}
+: ${SENDMAIL=/usr/lib/sendmail}
 # : ${LDFLAGS=} ${LIBS=} tickles old shell bug
 
 C="$CC $ALL_CFLAGS"
@@ -73,17 +73,6 @@ esac
 	ech='echo -n' dots='... '
 esac
 
-$ech >&3 "$0: testing permissions $dots"
-rm -f a.d &&
-date >a.d &&
-chmod 0 a.d &&
-{ test -w a.d || cp /dev/null a.d 2>/dev/null; } && {
-	echo >&3 "$n$0: This command should not be run with superuser permissions."
-	exit 1
-}
-echo >&3 OK
-rm -f a.d || exit
-
 $ech >&3 "$0: testing compiler for plausibility $dots"
 echo 'main() { return 0; }' >a.c
 rm -f a.exe a.out || exit
@@ -2053,7 +2042,7 @@ esac
 '') a='/* ' z='*/ ';;
 *) a= z=
 esac
-echo "$a#define SENDMAIL $SENDMAIL $z/* how to send mail */"
+echo "$a#define SENDMAIL \"$SENDMAIL\" $z/* how to send mail */"
 
 : configuring TZ_must_be_set
 echo "#define TZ_must_be_set 0 /* Must TZ be set for gmtime() to work?  */"
