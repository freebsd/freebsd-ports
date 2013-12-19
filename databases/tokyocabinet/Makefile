# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	tokyocabinet
PORTVERSION=	1.4.48
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://fallabs.com/${PORTNAME}/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A modern implementation of DBM


GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes


MAN1=		tcamgr.1 tcamttest.1 tcatest.1 tcbmgr.1 tcbmttest.1 tcbtest.1 \
		tcfmgr.1 tcfmttest.1 tcftest.1 \
		tchmgr.1 tchmttest.1 tchtest.1 tcucodec.1 tcumttest.1 \
		tcutest.1 tctmgr.1 tctmttest.1 tcttest.1
MAN3=		tcadb.3 tcbdb.3 tcfdb.3 tchdb.3 tclist.3 tcmap.3 \
		tcmdb.3 tcmpool.3 tcutil.3 tcxstr.3 tokyocabinet.3 tctree.3 \
		tctdb.3

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

NO_STAGE=	yes
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
# liblzma on 9-current does not have liblzma.h file.
.if ${PORT_OPTIONS:MLZMA}
CONFIGURE_ARGS+=	--enable-exlzma
LIB_DEPENDS+=		liblzma.so:${PORTSDIR}/archivers/lzmalib
.else
CONFIGURE_ARGS+=	--disable-exlzma
.endif
.if ${PORT_OPTIONS:MLZO}
CONFIGURE_ARGS+=	--enable-exlzo
LIB_DEPENDS+=		liblzo2.so:${PORTSDIR}/archivers/lzo2
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

.include <bsd.port.mk>
