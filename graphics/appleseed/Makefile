# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	appleseed
DISTVERSION=	1.5.2-beta
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern, physically-based production renderer

LICENSE=	MIT

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/OpenEXR \
		libxerces-c.so:textproc/xerces-c3

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}hq

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	not ported to it yet

USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build opengl

LDFLAGS+=	-lboost_atomic
CMAKE_ARGS=	-DUSE_STATIC_BOOST:BOOL=OFF -DUSE_STATIC_OIIO:BOOL=OFF \
		-DUSE_STATIC_OSL:BOOL=OFF -DWITH_DOXYGEN:BOOL=OFF \
		-DWITH_HEADERS:BOOL=OFF -DWITH_PYTHON:BOOL=OFF \
		-DWITH_TESTS:BOOL=OFF -DWARNINGS_AS_ERRORS:BOOL=OFF

.for lib in EXR OIIO OSL PNG SEEXPR XERCES ZLIB
CMAKE_ARGS+=	-DUSE_EXTERNAL_${lib}:BOOL=ON
.endfor

# Not ready for hier(7)-conforming installation yet
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PKGBASE}
PLIST_SUB=	APPHOME=${CMAKE_INSTALL_PREFIX}

SUB_FILES=	pkg-message
SUB_LIST:=	${PLIST_SUB}

OPTIONS_DEFINE=	EXAMPLES OSL DISNEY
OPTIONS_DEFAULT=	OSL DISNEY
OPTIONS_SUB=	yes

OSL_DESC=	Open Shading Language support
DISNEY_DESC=	Disney material support

EXAMPLES_CMAKE_OFF=	-DWITH_SAMPLES:BOOL=OFF

OSL_CMAKE_ON=	-DWITH_OSL:BOOL=ON
OSL_LIB_DEPENDS=	liboslexec.so:graphics/openshadinglanguage

DISNEY_CMAKE_ON=	-DWITH_DISNEY_MATERIAL:BOOL=ON
DISNEY_LIB_DEPENDS=	libOpenImageIO.so:graphics/openimageio \
			libSeExprEditor.so:graphics/seexpr

post-patch:
	@${REINPLACE_CMD} -e 's,atomic<int,boost::&,' \
		${WRKSRC}/src/appleseed/renderer/kernel/rendering/localsampleaccumulationbuffer.cpp
	@${RMDIR} ${WRKSRC}/sandbox/docs/api

.include <bsd.port.mk>
