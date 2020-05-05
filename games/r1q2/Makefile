# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	r1q2
PORTVERSION=	8012
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ LOCAL/danfe \
		http://old.r1ch.net/stuff/r1q2/src/
DISTNAME=	${PORTNAME}-b${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Enhanced Quake II client/server focusing on stability

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	sets the FPU rounding mode and precision (not available in fenv.h)

USES=		dos2unix gmake zip
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/binaries
ALL_TARGET=	#

LIBDIR=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S|${PREFIX}/||}"

OPTIONS_DEFINE=	GAME REF_GL DOCS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED REF_GL

FLAVOR_DESC=	Clients and servers
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)
REF_GL_DESC=	Build renderer (required for client)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	r1q2ded
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
ALL_TARGET+=	game
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MREF_GL}
USES+=		gl jpeg sdl
USE_GL=		gl
USE_SDL=	sdl
LIB_DEPENDS+=	libpng.so:graphics/png
ALL_TARGET+=	ref_gl
PLIST_SUB+=	REF_GL=""
.else
PLIST_SUB+=	REF_GL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|game$$(ARCH)|game|g' \
		${BUILD_WRKSRC}/game/Makefile

pre-build:
	@${FIND} ${BUILD_WRKSRC} -type d -depth 1 -exec ${MKDIR} {}/.depends \;

do-install:
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/client/quake2 \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/r1q2ded/r1q2ded \
		${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/game/game.so \
		${STAGEDIR}${LIBDIR}/baseq2
.endif
.if ${PORT_OPTIONS:MREF_GL}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ref_gl/ref_gl.so \
		${STAGEDIR}${LIBDIR}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/r1q2.txt ${WRKSRC}/readme.txt \
		${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
