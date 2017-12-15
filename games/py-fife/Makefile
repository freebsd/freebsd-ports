# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=		fife
PORTVERSION=		0.4.1
PORTREVISION=		5
CATEGORIES=		games
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Flexible Isometric Free Engine

LICENSE=		LGPL21

LIB_DEPENDS=		libvorbisfile.so:audio/libvorbis \
			libtinyxml.so:textproc/tinyxml \
			libboost_filesystem.so:devel/boost-libs \
			libpng.so:graphics/png

BROKEN_powerpc64=	fails to compile: fifePYTHON_wrap.cxx: relocation truncated to fit

USES=			openal:al pkgconfig cmake:outsource
USE_GL=			gl
USE_SDL=		sdl2 ttf2 image2
USE_XORG=		xcursor

USE_GITHUB=	yes
GH_ACCOUNT=	fifengine
GH_PROJECT=	fifengine

OPTIONS_DEFINE=		ZIP LOGGING

OPTIONS_MULTI=		GUISS COMP

OPTIONS_SUB=		yes

OPTIONS_MULTI_GUISS=	FIFECHAN CEGUI
GUISS_DESC=		GUI subsystem
FIFECHAN_DESC=		Fifechan GUI subsystem
CEGUI_DESC=		Crazy Eddi's GUI subsystem (must be build with OpenGL)

ZIP_DESC=		ZIP archive support
LOGGING_DESC=		Logging

OPTIONS_MULTI_COMP=	PYTHON LIBRARY
COMP_DESC=		Building components
PYTHON_DESC=		Build python extension module (need for unknown-horizons)
LIBRARY_DESC=		Build and install files for directly develop with C++

OPTIONS_DEFAULT=	FIFECHAN ZIP LOGGING PYTHON

FIFECHAN_CMAKE_BOOL=	fifechan
FIFECHAN_LIB_DEPENDS=	libfifechan_sdl.so:devel/fifechan

CEGUI_CMAKE_BOOL=	cegui
CEGUI_LIB_DEPENDS=	libCEGUIBase-0.so:graphics/cegui
CEGUI_USE=		gl=glew

ZIP_CMAKE_BOOL=		zip
LOGGING_CMAKE_BOOL=	logging

PYTHON_CMAKE_BOOL=	build-python
PYTHON_USES=		python:2
PYTHON_USE=		python=flavors
PYTHON_BUILD_DEPENDS=	${LOCALBASE}/bin/swig3.0:devel/swig30

LIBRARY_CMAKE_BOOL=	build-library
# For static library build
# LIBRARY_CMAKE_ON=	-Dbuild-library=ON -DBUILD_SHARED_LIBS=OFF
# LIBRARY_CMAKE_OFF=	-Dbuild-library=OFF

.include <bsd.port.mk>
