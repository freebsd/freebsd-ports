# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	openmw
PORTVERSION=	0.40.0
DISTVERSIONPREFIX=	openmw-
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	t@tobik.me
COMMENT=	Unofficial open source engine reimplementation of the game Morrowind

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/license/GPL3.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libBulletCollision.so:devel/bullet \
		libboost_thread.so:devel/boost-libs \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libosg.so:graphics/osg \
		libunshield.so:archivers/unshield

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	OpenMW

USES=		cmake:outsource compiler:c++14-lang ninja openal pkgconfig
USE_GL=		gl
USE_QT5=	qmake_build buildtools_build core gui network opengl \
		printsupport widgets
USE_SDL=	sdl2
USE_XORG=	xt

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=Release \
		-DDESIRED_QT_VERSION=5 \
		-DBUILD_OPENMW=ON \
		-DBUILD_BSATOOL=ON \
		-DBUILD_ESMTOOL=ON \
		-DBUILD_LAUNCHER=ON \
		-DBUILD_MWINIIMPORTER=ON \
		-DBUILD_ESSIMPORTER=ON \
		-DBUILD_OPENCS=ON \
		-DBUILD_WIZARD=ON \
		-DBUILD_WITH_CODE_COVERAGE=OFF \
		-DBUILD_UNITTEST=OFF \
		-DBUILD_NIFTEST=OFF \
		-DBUILD_MYGUI_PLUGIN=OFF \
		-DMORROWIND_DATA_FILES="${DATADIR}/data" \
		-DOPENMW_RESOURCE_FILES="${DATADIR}/resources" \
		-DGLOBAL_DATA_PATH="${PREFIX}/share"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
