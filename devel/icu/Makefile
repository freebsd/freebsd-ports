# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	3.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.software.ibm.com/software/globalization/icu/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	International Components for Unicode (from IBM)

OPTIONS=	THREADS "Build multi-threaded version of the library" on
CONFLICTS=	icu2-[0-9]*

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes

WRKSRC=			${WRKDIR}/icu/source

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigureICU
CONFIGURE_ARGS+=	${OPSYS}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-samples=no

USE_GMAKE=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" CC="${CC}" CXX="${CXX}"

MAN1+=	derb.1
MAN1+=	gencnval.1
MAN1+=	genrb.1
MAN1+=	icu-config.1
MAN1+=	makeconv.1
MAN1+=	pkgdata.1
MAN1+=	uconv.1
MAN8+=	decmn.8
MAN8+=	genccode.8
MAN8+=	gencmn.8
MAN8+=	gensprep.8
MAN8+=	genuca.8

ICUMAJOR=	${PORTVERSION:S/.//:R}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR}
PLIST_SUB+=	ICUVER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Segfault during build on ia64"
.endif

.if ${ARCH} != "sparc64"
post-patch:
	${REINPLACE_CMD} 's,-fPIC,-fpic,' ${WRKSRC}/config/mh-bsd-gcc
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads=yes
CONFIGURE_ENV+=		THREADSCPPFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCFLAGS="${PTHREAD_CFLAGS}" \
			THREADSCXXFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	--enable-threads=no
.endif

iotest cintltst intltest:
	-${GMAKE} -C ${WRKSRC}/test
	cd ${WRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/tools/ctestfw \
	    ./${.TARGET}

post-build test: iotest cintltst intltest

.include <bsd.port.post.mk>
