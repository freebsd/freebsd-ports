# New ports collection makefile for:	tokyocabinet
# Date created:		2007-12-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	tokyocabinet
PORTVERSION=	1.4.29
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A modern implementation of DBM

MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--enable-off64
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.in
.endif

MAN1=		tcamgr.1 tcatest.1 tcbmgr.1 tcbmttest.1 tcbtest.1 \
		tcfmgr.1 tcfmttest.1 tcftest.1 \
		tchmgr.1 tchmttest.1 tchtest.1 tcucodec.1 tcumttest.1 \
		tcutest.1 tctmgr.1 tctmttest.1 tcttest.1
MAN3=		tcadb.3 tcbdb.3 tcfdb.3 tchdb.3 tclist.3 tcmap.3 \
		tcmdb.3 tcmpool.3 tcutil.3 tcxstr.3 tokyocabinet.3 tctree.3 \
		tctdb.3

OPTIONS=	DEBUG "Debugging support" off \
		DEVEL "Development build" off \
		PROFILE "Profiling build" off \
		OFF64 "Use to compile on 64-bit system" off \
		FASTEST "Fastest run" off \
		SWAB "Swapping byte-orders build" off \
		UYIELD "Detecting race conditions" off \
		ZLIB "Disable ZLIB compression" off \
		BZIP2 "BZIP2 compression" on \
		PTHREAD "Disable POSIX thread support" off

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
.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif
.if defined(WITH_OFF64)
CONFIGURE_ARGS+=	--enable-off64
.endif
.if defined(WITH_FASTEST)
CONFIGURE_ARGS+=	--enable-fastest
.endif
.if defined(WITH_SWAB)
CONFIGURE_ARGS+=	--enable-swab
.endif
.if defined(WITH_UYIELD)
CONFIGURE_ARGS+=	--enable-uyield
.endif
.if defined(WITH_ZLIB)
CONFIGURE_ARGS+=	--disable-zlib
.endif
.if defined(WITHOUT_BZIP2)
CONFIGURE_ARGS+=	--disable-bzip
.endif
.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--disable-pthread
.endif
.if defined(WITH_SHARED)
CONFIGURE_ARGS+=	--disable-shared
.endif

SHLIB_VER=	8.20.0
SHLIB_VER_MAJ=	8

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

# Because gnomehack will search "(libdir)" and it doesn't work, we need
# to patch it manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		-e 's|@datarootdir@|@datarootdir@/doc|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
