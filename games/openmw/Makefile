# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openmw
DISTVERSIONPREFIX=	openmw-
DISTVERSION=	0.46.0
CATEGORIES=	games

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Unofficial open source engine reimplementation of the game Morrowind

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_thread.so:devel/boost-libs \
		libBulletCollision.so:devel/bullet \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libosg.so:graphics/osg \
		libunshield.so:archivers/unshield

USES=		cmake compiler:c++14-lang gl openal pkgconfig qt:5 sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMW
USE_GL=		gl
USE_QT=		core gui network opengl printsupport widgets buildtools_build \
		qmake_build
USE_SDL=	sdl2

CMAKE_ARGS=	-DDESIRED_QT_VERSION=5 \
		-DGLOBAL_DATA_PATH="${PREFIX}/share" \
		-DMORROWIND_DATA_FILES="${DATADIR}/data" \
		-DOPENMW_RESOURCE_FILES="${DATADIR}/resources"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
