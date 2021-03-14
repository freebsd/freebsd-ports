# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	appleseed
DISTVERSION=	2.1.0-beta
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern, physically-based production renderer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		liblz4.so:archivers/liblz4 \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/openexr \
		libIlmThread.so:graphics/ilmbase \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenImageIO.so:graphics/openimageio \
		libxerces-c.so:textproc/xerces-c3 \
		liboslexec.so:graphics/openshadinglanguage

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}hq

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	not ported to it yet

USES=		cmake compiler:c++11-lang shebangfix
SHEBANG_FILES=	scripts/*.py

CMAKE_ARGS=	-DWITH_PYTHON2_BINDINGS:BOOL=OFF \
		-DWITH_DOXYGEN:BOOL=OFF \
		-DINSTALL_HEADERS:BOOL=OFF \
		-DINSTALL_TESTS:BOOL=OFF \
		-DINSTALL_API_EXAMPLES:BOOL=OFF \
		-DWARNINGS_AS_ERRORS:BOOL=OFF

.for lib in BOOST EMBREE EXR OCIO OIIO OSL
CMAKE_ARGS+=	-DUSE_STATIC_${lib}:BOOL=OFF
.endfor

# Not ready for hier(7)-conforming installation yet
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PKGBASE}
PLIST_SUB=	APPHOME=${CMAKE_INSTALL_PREFIX}

SUB_FILES=	pkg-message
SUB_LIST:=	${PLIST_SUB}

OPTIONS_DEFINE=	EMBREE PYTHON STUDIO
OPTIONS_DEFAULT=	PYTHON STUDIO
OPTIONS_SUB=	yes

EMBREE_DESC=	Embree intersection backend support
EMBREE_LIB_DEPENDS=	libembree3.so:graphics/embree
EMBREE_CMAKE_ON=	-DWITH_EMBREE:BOOL=ON

PYTHON_USES=	gl python:3.5+,build,run
PYTHON_USE=	GL=gl
PYTHON_CMAKE_ON=	-DWITH_PYTHON3_BINDINGS:BOOL=ON

STUDIO_DESC=	Build appleseed.studio (Qt-based)
STUDIO_LIB_DEPENDS=	${PY_BOOST}
STUDIO_USES=	qt:5
STUDIO_USE=	QT=buildtools_build,qmake_build,concurrent,core,gui,opengl,widgets
STUDIO_CMAKE_OFF=	-DWITH_STUDIO:BOOL=OFF
STUDIO_IMPLIES=	PYTHON

post-patch:
	@${RMDIR} ${WRKSRC}/sandbox/docs/api
	@${RM} ${WRKSRC}/sandbox/share/cmake/Modules/FindOpenImageIO.cmake

.include <bsd.port.mk>

PATCH_ARGS+=	-l
