# New ports collection makefile for:	minetest
# Date created:		19 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minetest
PORTVERSION=	r20110623
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		https://bitbucket.org/celeron55/minetest/get/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An Infiniminer/Minecraft inspired game

BUILD_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht
RUN_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GL=		gl
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/celeron55-minetest-9bc10c75dff2

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS=	CLIENT	"Build client" on \
		SERVER	"Build server" on \
		OPTIMIZED_CFLAGS "Enabled additional optimizations" on

.include <bsd.port.options.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -funroll-loops
CXXFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -funroll-loops
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DBUILD_CLIENT=1
PLIST_SUB+=	CLIENT=""
.else
CMAKE_ARGS+=	-DBUILD_CLIENT=0
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_SERVER)
CMAKE_ARGS+=	-DBUILD_SERVER=1
PLIST_SUB+=	SERVER=""
.else
CMAKE_ARGS+=	-DBUILD_SERVER=0
PLIST_SUB+=	SERVER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/src/porting.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindIrrlicht.cmake

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.txt ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/minetest.conf.example ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
