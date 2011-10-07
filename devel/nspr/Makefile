# Ports collection Makefile for:	nspr
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-experimental/devel/nspr/Makefile,v 1.6 2008/03/12 13:06:56 ahze Exp $

PORTNAME=	nspr
DISTVERSION=	4.8.9
CATEGORIES=	devel
MASTER_SITES=	MOZILLA
MASTER_SITE_SUBDIR=	nspr/releases/v${PORTVERSION}/src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	A platform-neutral API for system level and libc like functions

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../configure
CONFIGURE_ARGS=	--disable-debug \
		--with-pthreads
CONFIGURE_ENV=	BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

MAKE_ENV=	DIST=${WRKSRC}/dist

LIBS=		libnspr4.so.1 libplc4.so.1 libplds4.so.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g ; s,echo aout,echo elf,g' ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${MKDIR} ${PREFIX}/include/nspr
	${TAR} -C ${WRKSRC}/dist/include --dereference -cf - . | \
	    	${TAR} -C ${PREFIX}/include -xof -
	${FIND} ${PREFIX}/include/nspr -type d | \
	    	${XARGS} ${CHMOD} 0755
	${FIND} ${PREFIX}/include/nspr -type f | \
	    	${XARGS} ${CHMOD} ${SHAREMODE}
	${TAR} -C ${WRKSRC}/dist/lib --dereference -cf - . | \
	    	${TAR} -C ${PREFIX}/lib -xof -
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/config/nspr.pc ${PREFIX}/libdata/pkgconfig
.for lib in ${LIBS}
.if defined(STRIP) && ${STRIP} != ""
	${STRIP_CMD} ${PREFIX}/lib/${lib}
.endif
	${CHMOD} ${BINMODE} ${PREFIX}/lib/${lib}
	${LN} -sf ${lib} ${PREFIX}/lib/${lib:R}
.endfor

prtests:
	${SETENV} PTHREAD_LIBS="${PTHREAD_LIBS}" ${GMAKE} -C ${WRKSRC}/pr/tests
	${LN} -sf libmy.so.1 ${WRKSRC}/pr/tests/dll/libmy.so
	cd ${WRKSRC}/pr/tests && ../../../pr/tests/runtests.sh

libtests:
	${GMAKE} -C ${WRKSRC}/lib/tests
	${WRKSRC}/lib/tests/string
	${WRKSRC}/lib/tests/base64t
	# The test below is commented out, because arena requires
	# command-line arguments. If you can provide reasonable values
	# for it, please contact ${MAINTAINER}. Thank you.
	#	${WRKSRC}/lib/tests/arena
	#

test: libtests prtests

#regression-test: test

#.if defined(PACKAGE_BUILDING)
#post-build: test
#.else
post-build:
	#
	# Please, consider running ``make test'' to find any
	# possible build problems.
	#
#.endif

.include <bsd.port.post.mk>
