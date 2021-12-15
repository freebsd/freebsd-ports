PORTNAME=	openmw
PORTREVISION=	1
DISTVERSIONPREFIX=	openmw-
DISTVERSION=	0.47.0
CATEGORIES=	games

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Unofficial open source engine reimplementation of the game Morrowind

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libboost_thread.so:devel/boost-libs \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libBulletCollision.so:devel/bullet@double \
		libosg.so:graphics/osg \
		libRecast.so:graphics/recastnavigation \
		libunshield.so:archivers/unshield \
		liblz4.so:archivers/liblz4

USES=		cmake compiler:c++17-lang gl openal pkgconfig qt:5 sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMW
USE_GL=		gl
USE_QT=		core gui network opengl printsupport widgets buildtools_build \
		qmake_build
USE_SDL=	sdl2

CMAKE_ARGS=	-DDESIRED_QT_VERSION=5 \
		-DOPENMW_USE_SYSTEM_BULLET=ON \
		-DOPENMW_USE_SYSTEM_RECASTNAVIGATION=ON \
		-DGLOBAL_DATA_PATH="${PREFIX}/share" \
		-DMORROWIND_DATA_FILES="${DATADIR}/data" \
		-DOPENMW_RESOURCE_FILES="${DATADIR}/resources"

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	BUILD_DOCS
DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen \
			sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		python:build

PORTDOCS=	*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
