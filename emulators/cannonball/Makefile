# $FreeBSD$

PORTNAME=	cannonball
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31
CATEGORIES=	emulators games

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Enhanced OutRun Engine

LICENSE=	MAME-LICENSE
LICENSE_NAME=	MAME license
LICENSE_FILE=	${WRKSRC}/docs/license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/boost/exception/all.hpp:devel/boost-libs

USES=		cmake:insource gl pkgconfig sdl
USE_SDL=	sdl2
USE_GL=		gl glu

CMAKE_ARGS+=	${WRKSRC}/cmake \
		-DTARGET=linux.cmake

CFLAGS+=	-I${LOCALBASE}/include

USE_GITHUB=	yes
GH_ACCOUNT=	djyt

BUILD_WRKSRC=		${WRKSRC}/cmake
CONFIGURE_WRKSRC=	${WRKSRC}/cmake

SUB_FILES=	${PORTNAME}.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/res
	${MKDIR} ${STAGEDIR}${DATADIR}/conf
	${INSTALL_DATA} ${WRKSRC}/cmake/res/tilemap.bin ${STAGEDIR}${DATADIR}/res/tilemap.bin
	${INSTALL_DATA} ${WRKSRC}/cmake/res/tilepatch.bin ${STAGEDIR}${DATADIR}/res/tilepatch.bin
	${INSTALL_DATA} ${WRKSRC}/cmake/config.xml ${STAGEDIR}${DATADIR}/conf/config.xml
	${INSTALL_MAN} ${WRKSRC}/docs/cannonball.6 ${STAGEDIR}${MAN1PREFIX}/man/man6
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/cmake/cannonball ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
