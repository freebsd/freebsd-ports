#!/bin/sh

if [ -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "Pike configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 11 \
FreeType	"TrueType font rendering" OFF \
JPEG		"support JPEG" OFF \
threads		"threads support" ON \
GDBM		"GNU database manager support" OFF \
zlib		"zlib library support" ON \
gmp		"support bignums" ON \
readline	"support for command line editing" ON \
MySQL		"MySQL database support" OFF \
PostgreSQL	"PostgreSQL database support" OFF \
mSQL		"mSQL database support" OFF \
ssl	        "SSL support" OFF \
2> /tmp/checklist.tmp.$$
retval=$?

if [ -s /tmp/checklist.tmp.$$ ]; then
	set `cat /tmp/checklist.tmp.$$`
fi
rm -f /tmp/checklist.tmp.$$

case $retval in
	0)	if [ -z "$*" ]; then
			echo "Nothing selected"
		fi
		;;
	1)	echo "Cancel pressed."
		exit 1
		;;
esac

mkdir -p ${WRKDIRPREFIX}${CURDIR}
> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"FreeType\")
			echo 'LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-ttflib' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			FreeType=1
			;;
		\"threads\")
			threads=1
			;;
		\"gmp\")
			echo '.if ${OSVERSION} >= 500000' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo '.endif' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-gmp' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			gmp=1
			;;
		\"readline\")
			echo 'CONFIGURE_ARGS+=	--with-readline' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			readline=1
			;;
		\"JPEG\")
			echo 'LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-jpeg=${PREFIX}' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			JPEG=1
			;;
		\"GDBM\")
			echo 'LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc 
			echo 'CONFIGURE_ARGS+=	--with-gdbm=${PREFIX}' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			GDBM=1
			;;
		\"zlib\")
			echo 'CONFIGURE_ARGS+=	--with-zlib' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			zlib=1
			;;
		\"MySQL\")
			echo 'LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-mysql=${PREFIX}' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			MySQL=1
			;;
		\"PostgreSQL\")
			echo 'USE_PGSQL=		yes' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}/pgsql' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			PostgresSQL=1
			;;
		\"mSQL\")
			echo 'BUILD_DEPENDS+=		msql:${PORTSDIR}/databases/msql' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo 'CONFIGURE_ARGS+=	--with-msql=${PREFIX}' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			mSQL=1
			;;
		\"ssl\")
			echo 'CONFIGURE_ARGS+= --with-ssleay' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			ssl=1
			;;
	esac
	shift
done
if [ -z "$FreeType" ]; then
	echo 'CONFIGURE_ARGS+=  --without-ttflib' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$threads" ]; then
	echo 'CONFIGURE_ARGS+=  --without-threads' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$GDBM" ]; then
	echo 'CONFIGURE_ARGS+=  --without-gdbm' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$zlib" ]; then
	echo 'CONFIGURE_ARGS+=  --without-zlib' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$MySQL" ]; then
	echo 'CONFIGURE_ARGS+=  --without-mysql' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$PostgreSQL" ]; then
	echo 'CONFIGURE_ARGS+=  --without-postgresql' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$mSQL" ]; then
	echo 'CONFIGURE_ARGS+=  --without-msql' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$gmp" ]; then
	echo 'CONFIGURE_ARGS+=  --without-gmp --without-bignums' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$JPEG" ]; then
	echo 'CONFIGURE_ARGS+=  --without-jpeg' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
if [ -z "$readline" ]; then
	echo 'CONFIGURE_ARGS+=  --without-readline' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
if [ -z "$ssl" ]; then
	echo 'CONFIGURE_ARGS+=  --without-ssl' >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc  
fi
fi
