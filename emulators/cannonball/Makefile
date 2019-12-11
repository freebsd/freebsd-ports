# $FreeBSD$

PORTNAME=	cannonball
DISTVERSION=	g20191023
PORTREVISION=	1
CATEGORIES=	emulators games

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Enhanced OutRun Engine

LICENSE=	MAME-LICENSE
LICENSE_NAME=	MAME license
LICENSE_FILE=	${WRKSRC}/docs/license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		cmake:insource pkgconfig sdl
USE_SDL=	sdl2

CMAKE_ARGS+=	${WRKSRC}/cmake \
		-DBSD_PREFIX_PATH=${LOCALBASE} \
		-DTARGET=bsd

USE_GITHUB=	yes
GH_ACCOUNT=	djyt
GH_TAGNAME=	b6aa525

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
