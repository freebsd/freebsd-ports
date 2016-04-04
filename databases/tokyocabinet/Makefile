# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	tokyocabinet
PORTVERSION=	1.4.48
CATEGORIES=	databases
MASTER_SITES=	LOCAL/kuriyama \
		http://fallabs.com/${PORTNAME}/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Modern implementation of DBM

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG DEVEL FASTEST LZMA LZO PTHREAD PROFILE SHARED SWAB UYIELD DOCS
OPTIONS_DEFAULT=	PTHREAD SHARED
DEBUG_DESC=	Debugging support
DEVEL_DESC=	Development build
FASTEST_DESC=	Fastest run
LZMA_DESC=	LZMA codec
LZO_DESC=	LZO codec
PTHREAD_DESC=	Enable POSIX thread support
PROFILE_DESC=	Profiling build
SHARED_DESC=	Shared build
SWAB_DESC=	Swapping byte-orders build
UYIELD_DESC=	Detecting race conditions

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.in
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif
.if ${PORT_OPTIONS:MDEVEL}
CONFIGURE_ARGS+=	--enable-devel
.endif
.if ${PORT_OPTIONS:MFASTEST}
CONFIGURE_ARGS+=	--enable-fastest
.endif
# to not confuse with system liblzma
.if ${PORT_OPTIONS:MLZMA}
CONFIGURE_ARGS+=	--enable-exlzma
LIB_DEPENDS+=		liblzma.so.1:archivers/lzmalib
.else
CONFIGURE_ARGS+=	--disable-exlzma
.endif
.if ${PORT_OPTIONS:MLZO}
CONFIGURE_ARGS+=	--enable-exlzo
LIB_DEPENDS+=		liblzo2.so:archivers/lzo2
.else
CONFIGURE_ARGS+=	--disable-exlzo
.endif
.if ! ${PORT_OPTIONS:MPTHREAD}
CONFIGURE_ARGS+=	--disable-pthread
.endif
.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-profile
.endif
.if ! ${PORT_OPTIONS:MSHARED}
CONFIGURE_ARGS+=	--disable-shared
.endif
.if ${PORT_OPTIONS:MSWAB}
CONFIGURE_ARGS+=	--enable-swab
.endif
.if ${PORT_OPTIONS:MUYIELD}
CONFIGURE_ARGS+=	--enable-uyield
.endif

SHLIB_VER=	9.11.0
SHLIB_VER_MAJ=	9

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

# Because gnomehack will search "(libdir)" and it doesn't work, we need
# to patch it manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		-e 's|@datarootdir@|@datarootdir@/doc|' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/libexec/tcawmgr.cgi

.include <bsd.port.mk>
