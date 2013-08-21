# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME?=	openimageio
PORTVERSION=	1.2.0
PORTREVISION?=	0
CATEGORIES?=	graphics multimedia

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO graphics library

LICENSE?=	BSD

LIB_DEPENDS?=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		hdf5:${PORTSDIR}/science/hdf5-18 \
		opencv_legacy:${PORTSDIR}/graphics/opencv \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		webp:${PORTSDIR}/graphics/webp

USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio
GH_TAGNAME=	Release-${PORTVERSION}
GH_COMMIT=	f4d79c0
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-${GH_COMMIT}/src

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

USES=		cmake:outsource
CMAKE_ARGS?=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DNOTHREADS:BOOL=OFF \
		-DUSE_TBB:BOOL=OFF \
		-DSTOP_ON_WARNING:BOOL=OFF

USE_LDCONFIG=	yes

.if defined(OIIO_PYBIND)
PLIST=		${PKGDIR}/pkg-plist-pybind
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=ON
CMAKE_ARGS+=	-DOIIO_BUILD_TOOLS:BOOL=OFF
.else
PLIST=		${PKGDIR}/pkg-plist
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=OFF
CMAKE_ARGS+=	-DOIIO_BUILD_TOOLS:BOOL=ON
.endif

.if !defined(OIIO_PYBIND)
OPTIONS_DEFINE=		DOCS IMAGEVIEWER OCIO
OPTIONS_DEFAULT=	DOCS IMAGEVIEWER OCIO

IMAGEVIEWER_DESC=	Build image viewer
OCIO_DESC=		Colour management support
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DINSTALL_DOCS:BOOL=ON
.else
CMAKE_ARGS+=	-DINSTALL_DOCS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MIMAGEVIEWER}
USE_GL=		glew
USE_QT4=	corelib gui opengl qmake_build moc_build rcc_build uic_build
CMAKE_ARGS+=	-DUSE_QT:BOOL=ON -DUSE_OPENGL:BOOL=ON
CMAKE_ENV+=	QTDIR=${QT_PREFIX} QT_INCLUDES=${QT_INCDIR}
PLIST_SUB+=	IMAGEVIEWER=""
.else
CMAKE_ARGS+=	-DUSE_OPENGL:BOOL=OFF -DUSE_QT:BOOL=OFF
PLIST_SUB+=	IMAGEVIEWER="@comment "
.endif

.if ${PORT_OPTIONS:MOCIO}
CMAKE_ARGS+=	-DUSE_OCIO:BOOL=ON
LIB_DEPENDS+=	OpenColorIO:${PORTSDIR}/graphics/opencolorio
.else
CMAKE_ARGS+=	-DUSE_OCIO:BOOL=OFF
.endif

post-install:
.if !defined(OIIO_PYBIND)
	cd ${PREFIX}/lib && ${LN} -sf libOpenImageIO.so.1.2 libOpenImageIO.so.1
.endif

.include <bsd.port.mk>
