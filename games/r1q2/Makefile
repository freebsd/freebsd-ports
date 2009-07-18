# New ports collection makefile for:	r1q2
# Date created:				16 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	r1q2
PORTVERSION=	7904
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.r1ch.net/stuff/r1q2/src/
DISTNAME=	${PORTNAME}-b${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced Quake II client/server focusing on stability

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/binaries
ALL_TARGET=	#

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so file" off \
		REF_GL "Build renderer (required by CLIENT)" on

MAKE_ENV=	LIBDIR="${LIBDIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT and DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	r1q2ded
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
ALL_TARGET+=	game
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if !defined(WITHOUT_REF_GL)
USE_GL=		yes
USE_SDL=	sdl
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
ALL_TARGET+=	ref_gl
PLIST_SUB+=	REF_GL=""
.else
PLIST_SUB+=	REF_GL="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|game$$(ARCH)|game|g' \
		${BUILD_WRKSRC}/game/Makefile

pre-build:
	@${FIND} ${BUILD_WRKSRC} -type d -depth 1 -exec ${MKDIR} {}/.depends \;

do-install:
.if !defined(WITHOUT_CLIENT)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/client/quake2 \
		${PREFIX}/bin/${PORTNAME}
.endif
.if !defined(WITHOUT_DEDICATED)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/r1q2ded/r1q2ded ${PREFIX}/bin
.endif
	${MKDIR} ${LIBDIR}/baseq2
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/game/game.so ${LIBDIR}/baseq2
.endif
.if !defined(WITHOUT_REF_GL)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ref_gl/ref_gl.so ${LIBDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/r1q2.txt ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
