# New ports collection makefile for:	tokyocabinet
# Date created:		2007-12-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	tokyocabinet
PORTVERSION=	1.2.11
CATEGORIES=	databases
MASTER_SITES=	http://tokyocabinet.sourceforge.net/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A modern implementation of DBM

CONFIGURE_ARGS=	--enable-off64
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if !defined (NO_INSTALL_MANPAGES)
MAN1=		tcamgr.1 tcatest.1 tcbmgr.1 tcbmttest.1 tcbtest.1 \
		tchmgr.1 tchmttest.1 tchtest.1 tcucodec.1 tcumttest.1 \
		tcutest.1
MAN3=		tcadb.3 tcbdb.3 tchdb.3 tcutil.3 tokyocabinet.3
.endif
DOCS=		COPYING ChangeLog README THANKS
BINS=		tcamgr tcatest tcbmgr tcbmttest tcbtest tchmgr tchmttest \
		tchtest tcucodec tcumttest tcutest
LIBS=		libtokyocabinet.a
INCLUDES=	tcbdb.h tchdb.h tcutil.h

OPTIONS=	DEBUG "Debugging support" off \
		DEVEL "Development build" off \
		PROFILE "Profiling build" off \
		OFF64 "Use to compile on 64-bit system" off \
		FASTEST "Fastest run" off \
		SWAB "Swapping byte-orders build" off \
		UYIELD "Detecting race conditions" off \
		ZLIB "Disable ZLIB compression" off \
		PTHREAD "Disable POSIX thread support" off

.include <bsd.port.pre.mk>

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
.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--disable-pthread
.endif
.if defined(WITH_SHARED)
CONFIGURE_ARGS+=	--disable-shared
.endif

# Because gnomehack will search "(libdir)" and it doesn't work, we need
# to patch it manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin/
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/,} ${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${MAN3:S,^,${WRKSRC}/man/,} ${MAN3PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR}/)
.endif
.for i in ${LIBS}
	@${CP} ${WRKSRC}/${i} ${PREFIX}/lib/
.endfor
.for j in ${INCLUDES}
	@${CP} ${WRKSRC}/${j} ${PREFIX}/include/
.endfor
	@${CP} ${WRKSRC}/tokyocabinet.pc ${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
