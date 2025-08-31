PORTNAME=	fife
PORTVERSION=	0.4.2
PORTREVISION=	12
CATEGORIES=	games
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Flexible Isometric Free Engine
WWW=		https://www.fifengine.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libtinyxml.so:textproc/tinyxml \
		libboost_filesystem.so:devel/boost-libs \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gl openal:al pkgconfig sdl xorg
USE_GL=		gl glew
USE_LDCONFIG=	yes
USE_SDL=	sdl2 ttf2 image2
USE_XORG=	xcursor

USE_GITHUB=	yes
GH_ACCOUNT=	fifengine
GH_PROJECT=	fifengine

OPTIONS_DEFINE=	LOGGING

OPTIONS_MULTI=		GUISS COMP
OPTIONS_MULTI_GUISS=	FIFECHAN CEGUI
OPTIONS_MULTI_COMP=	PYTHON LIBRARY
OPTIONS_DEFAULT=	FIFECHAN LOGGING PYTHON

OPTIONS_SUB=		yes

GUISS_DESC=		GUI subsystem
FIFECHAN_DESC=		Fifechan GUI subsystem
CEGUI_DESC=		Crazy Eddi's GUI subsystem (must be build with OpenGL)

LOGGING_DESC=		Logging

COMP_DESC=		Building components
PYTHON_DESC=		Build python extension module (need for unknown-horizons)
LIBRARY_DESC=		Build and install files for directly develop with C++

FIFECHAN_CMAKE_BOOL=	fifechan
FIFECHAN_LIB_DEPENDS=	libfifechan_sdl.so:devel/fifechan

CEGUI_CMAKE_BOOL=	cegui
CEGUI_LIB_DEPENDS=	libCEGUIBase-0.so:graphics/cegui

LOGGING_CMAKE_BOOL=	logging

PYTHON_CMAKE_BOOL=	build-python
PYTHON_USES=		python
PYTHON_USE=		python=flavors
PYTHON_BUILD_DEPENDS=	${LOCALBASE}/bin/swig:devel/swig
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

LIBRARY_CMAKE_BOOL=	build-library
# For static library build
# LIBRARY_CMAKE_ON=	-Dbuild-library=ON -DBUILD_SHARED_LIBS=OFF
# LIBRARY_CMAKE_OFF=	-Dbuild-library=OFF

post-patch:
	@${REINPLACE_CMD} -e 's,bfs::extension,GetExtension,g' \
		${WRKSRC}/engine/core/loaders/native/map/atlasloader.cpp \
		${WRKSRC}/engine/core/loaders/native/map/maploader.cpp \
		${WRKSRC}/engine/core/loaders/native/map/objectloader.cpp \
		${WRKSRC}/engine/core/gui/fifechan/fifechanmanager.cpp

.include <bsd.port.mk>
