# New ports collection makefile for:	minetest
# Date created:		19 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minetest
DISTVERSION=	0.2.20110922_1
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An Infiniminer/Minecraft inspired game

LIB_DEPENDS=	Irrlicht.1:${PORTSDIR}/x11-toolkits/irrlicht \
		sqlite3:${PORTSDIR}/databases/sqlite3

USE_CMAKE=	yes
USE_GL=		gl
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/celeron55-minetest-bdf5490

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS=	CLIENT "Build client" on \
		SERVER "Build server" on \
		OPTIMIZED_CFLAGS "Enabled additional optimizations" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DENABLE_GETTEXT:BOOL=NO
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
CXXFLAGS+=	-DNDEBUG
. if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -funroll-loops
CXXFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -funroll-loops
. endif
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
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
	${INSTALL_DATA} ${WRKSRC}/doc/changelog.txt ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/minetest.conf.example ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
