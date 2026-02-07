PORTNAME=	tokyocabinet
PORTVERSION=	1.4.48
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/kuriyama \
		https://dbmx.net/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern implementation of DBM
WWW=		https://dbmx.net/tokyocabinet/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DEBUG DEVEL FASTEST LZMA LZO PTHREAD PROFILE SHARED SWAB UYIELD DOCS
OPTIONS_DEFAULT=	PTHREAD SHARED
OPTIONS_SUB=	yes

DEVEL_DESC=	Development build
FASTEST_DESC=	Fastest run
LZMA_DESC=	LZMA codec
LZO_DESC=	LZO codec
PTHREAD_DESC=	Enable POSIX thread support
PROFILE_DESC=	Profiling build
SHARED_DESC=	Shared build
SWAB_DESC=	Swapping byte-orders build
UYIELD_DESC=	Detecting race conditions

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_PREVENTS=			LZMA

DEVEL_CONFIGURE_ENABLE=		devel

FASTEST_CONFIGURE_ENABLE=	fastest

# to not confuse with system liblzma
LZMA_CONFIGURE_ENABLE=		exlzma
LZMA_LIB_DEPENDS=		liblzma.so.1:archivers/lzmalib
LZMA_PREVENTS=			DEBUG

LZO_CONFIGURE_ENABLE=		exlzo
LZO_LIB_DEPENDS=		liblzo2.so:archivers/lzo2

PTHREAD_CONFIGURE_ENABLE=	pthread

PROFILE_CONFIGURE_ENABLE=	profile
PROFILE_PREVENTS=		SHARED

SHARED_CONFIGURE_ENABLE=	shared
SHARED_PREVENTS=		PROFILE

SWAB_CONFIGURE_ENABLE=		swab

UYIELD_CONFIGURE_ENABLE=	uyield

SHLIB_VER=	9.11.0
SHLIB_VER_MAJ=	9

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

post-patch:
	${REINPLACE_CMD} -e 's|@datarootdir@|@datarootdir@/doc|' \
		${WRKSRC}/Makefile.in

post-patch-FASTEST-on:
	${REINPLACE_CMD} -e 's|-fforce-addr||' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/libexec/tcawmgr.cgi

post-install-SHARED-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
