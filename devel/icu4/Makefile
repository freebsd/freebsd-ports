# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	3.8.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ICU4C/${PORTVERSION}
DISTNAME=	icu4c-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	International Components for Unicode (from IBM)

OPTIONS=	THREADS "Build thread-safe version of the library" on
CONFLICTS=	icu2-[0-9]*

USE_LDCONFIG=		yes

WRKSRC=			${WRKDIR}/icu/source

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	runConfigureICU
CONFIGURE_ARGS+=	${OPSYS}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-samples=no

USE_GMAKE=		yes

MAN1+=	derb.1
MAN1+=	genbrk.1
MAN1+=	gencnval.1
MAN1+=	genctd.1
MAN1+=	genrb.1
MAN1+=	icu-config.1
MAN1+=	makeconv.1
MAN1+=	pkgdata.1
MAN1+=	uconv.1
MAN8+=	icupkg.8
MAN8+=	genccode.8
MAN8+=	gencmn.8
MAN8+=	gensprep.8
MAN8+=	genuca.8

ICUMAJOR=	${PORTVERSION:S/.//:R}
PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUMINOR=1
PLIST_SUB+=	ICUVER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${CC:T} == "cc"
CFLAGS:=	${CFLAGS:N-funroll-loops:N-O*:N-*strict-aliasing} -O2 -fno-strict-aliasing
.endif
.if ${CXX:T} == "c++"
CXXFLAGS:=	${CXXFLAGS:N-funroll-loops:N-O*:N-*strict-aliasing} -O2 -fno-strict-aliasing
.endif
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads=no
.else
# This builds thread-safe, but not the thread-using version:
CONFIGURE_ARGS+=	--enable-weak-threads
post-patch:
	${REINPLACE_CMD} -e 's,\(THREADSC.*FLAGS\).*,\1=${PTHREAD_CFLAGS},g' ${WRKSRC}/config/mh-bsd-gcc
.endif

iotest cintltst intltest:
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
	-${GMAKE} -C ${WRKSRC}/test
	cd ${WRKSRC}/test/${.TARGET} && ${SETENV} \
	    LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/tools/ctestfw \
	    ./${.TARGET}
.endif

post-build test: iotest cintltst intltest

.include <bsd.port.post.mk>
