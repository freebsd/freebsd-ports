# New ports collection makefile for:	tokyocabinet
# Date created:		2007-12-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	tokyocabinet
PORTVERSION=	1.4.47
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://1978th.net/tokyocabinet/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A modern implementation of DBM

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.in
.endif

MAN1=		tcamgr.1 tcamttest.1 tcatest.1 tcbmgr.1 tcbmttest.1 tcbtest.1 \
		tcfmgr.1 tcfmttest.1 tcftest.1 \
		tchmgr.1 tchmttest.1 tchtest.1 tcucodec.1 tcumttest.1 \
		tcutest.1 tctmgr.1 tctmttest.1 tcttest.1
MAN3=		tcadb.3 tcbdb.3 tcfdb.3 tchdb.3 tclist.3 tcmap.3 \
		tcmdb.3 tcmpool.3 tcutil.3 tcxstr.3 tokyocabinet.3 tctree.3 \
		tctdb.3

OPTIONS=	DEBUG "Debugging support" off \
		DEVEL "Development build" off \
		FASTEST "Fastest run" off \
		LZMA "Enable LZMA codec" off \
		LZO "Enable LZO codec" off \
		PTHREAD "Enable POSIX thread support" on \
		PROFILE "Profiling build" off \
		SHARED "Shared build" on \
		SWAB "Swapping byte-orders build" off \
		UYIELD "Detecting race conditions" off

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif
.if defined(WITH_DEVEL)
CONFIGURE_ARGS+=	--enable-devel
.endif
.if defined(WITH_FASTEST)
CONFIGURE_ARGS+=	--enable-fastest
.endif
# liblzma on 9-current does not have liblzma.h file.
.if defined(WITH_LZMA) || exists(${LOCALBASE}/include/liblzma.h)
CONFIGURE_ARGS+=	--enable-exlzma
LIB_DEPENDS+=		lzma:${PORTSDIR}/archivers/lzmalib
.endif
.if defined(WITH_LZO) || exists(${LOCALBASE}/lib/liblzo2.so)
CONFIGURE_ARGS+=	--enable-exlzo
LIB_DEPENDS+=		lzo2:${PORTSDIR}/archivers/lzo2
.endif
.if defined(WITHOUT_PTHREAD)
CONFIGURE_ARGS+=	--disable-pthread
.endif
.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif
.if defined(WITHOUT_SHARED)
CONFIGURE_ARGS+=	--disable-shared
.endif
.if defined(WITH_SWAB)
CONFIGURE_ARGS+=	--enable-swab
.endif
.if defined(WITH_UYIELD)
CONFIGURE_ARGS+=	--enable-uyield
.endif

SHLIB_VER=	9.10.0
SHLIB_VER_MAJ=	9

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

# Because gnomehack will search "(libdir)" and it doesn't work, we need
# to patch it manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		-e 's|@datarootdir@|@datarootdir@/doc|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
