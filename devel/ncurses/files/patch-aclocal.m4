--- aclocal.m4.orig	2015-01-06 18:02:30 UTC
+++ aclocal.m4
@@ -5688,7 +5688,7 @@ CF_EOF
 			EXTRA_LDFLAGS="${cf_ld_rpath_opt}\${RPATH_LIST} $EXTRA_LDFLAGS"
 		fi
 		CF_SHARED_SONAME
-		MK_SHARED_LIB='${LD} -shared -Bshareable -soname=`basename $[@]` -o $[@]'
+		MK_SHARED_LIB='${CC} ${CFLAGS} -shared -Wl,-soname,`basename $[@]` -o $[@]'
 		;;
 	netbsd*) #(vi
 		CC_SHARED_OPTS="$CC_SHARED_OPTS -DPIC"
