PORTNAME=	colobot
DISTVERSIONPREFIX=	${PORTNAME}-gold-
DISTVERSION=	0.1.12
DISTVERSIONSUFFIX=	-alpha
PORTREVISION=	7
CATEGORIES=	games education
MASTER_SITES=	https://colobot.info/files/music/:music
DISTFILES=	colobot-music_ogg_0.1.12-alpha.tar.gz:music

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Educational game aiming to teach programming to kids

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libopenal.so:audio/openal-soft \
		libphysfs.so:devel/physfs \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lang gl gettext-runtime \
		gettext-tools:build localbase:ldflags openal python:build \
		sdl shebangfix
USE_SDL=	image2 ttf2
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	colobot:colobot-data:c467bd9:data

LDFLAGS_i386=	-Wl,-znotext
SHEBANG_FILES=	data/i18n-tools/scripts/process_translations.py

post-extract:
	@${MV} ${WRKDIR}/colobot-data-c467bd9/* ${WRKSRC}/data
	@${MV} ${WRKDIR}/*.ogg ${WRKDIR}/LICENSE.txt ${WRKSRC}/data/music/
	@${REINPLACE_CMD} 's|$${CMAKE_INSTALL_PREFIX}/games|$${CMAKE_INSTALL_PREFIX}/bin|g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|PLATFORM_MACOSX|PLATFORM_MACOSX OR PLATFORM_OTHER|g' ${WRKSRC}/src/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/FindGLEW.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/FindPhysFS.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/FindSDL2.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/FindSDL2_image.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/FindSDL2_ttf.cmake
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/tools/check-levels.sh
	${REINPLACE_CMD} 's|python|${PYTHON_CMD}|' ${WRKSRC}/data/tools/*.sh

.include <bsd.port.mk>
