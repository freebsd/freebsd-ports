PORTNAME=	openmw
DISTVERSIONPREFIX=	openmw-
DISTVERSION=	0.48.0
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Unofficial open source engine reimplementation of the game Morrowind
WWW=		https://openmw.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so.60:multimedia/ffmpeg \
		libboost_thread.so:devel/boost-libs \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libBulletCollision.so:devel/bullet@double \
		libosg.so:graphics/osg \
		libRecast.so:graphics/recastnavigation \
		libunshield.so:archivers/unshield \
		liblz4.so:archivers/liblz4 \
		libicui18n.so:devel/icu \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++17-lang desktop-file-utils gl luajit openal \
		pkgconfig qt:5 sdl sqlite xorg
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMW
USE_GL=		gl
USE_QT=		core gui network opengl printsupport widgets buildtools:build \
		qmake:build
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
