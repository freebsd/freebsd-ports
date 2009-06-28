# Ports collection Makefile for:	nspr
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-experimental/devel/nspr/Makefile,v 1.6 2008/03/12 13:06:56 ahze Exp $

PORTNAME=	nspr
DISTVERSION=	4.8
CATEGORIES=	devel
#MASTER_SITES=	LOCAL/ahze
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	nspr/releases/v${PORTVERSION}/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A platform-neutral API for system level and libc like functions

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

USE_LDCONFIG=	yes
USE_GMAKE=	yes
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
.if ${OSVERSION} < 601104
	@${REINPLACE_CMD} -e 's|pthread_cond_wait|_pthread_cond_wait|g' \
	    	${WRKSRC}/../pr/src/md/unix/pthreads_user.c \
		${WRKSRC}/../pr/src/pthreads/ptsynch.c
.endif

do-install:
	${MKDIR} ${PREFIX}/include/nspr
	${TAR} -C ${WRKSRC}/dist/include --dereference -cf - . | \
		${TAR} -C ${PREFIX}/include -xf -
	${TAR} -C ${WRKSRC}/dist/lib --dereference -cf - . | \
		${TAR} -C ${PREFIX}/lib -xf -
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/config/nspr.pc ${PREFIX}/libdata/pkgconfig
.for lib in ${LIBS}
	${LN} -sf ${lib} ${PREFIX}/lib/${lib:R}
.endfor

prtests:
	env PTHREAD_LIBS="${PTHREAD_LIBS}" ${GMAKE} -C ${WRKSRC}/pr/tests
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
