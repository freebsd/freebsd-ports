# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME?=	openimageio
PORTVERSION=	1.1.2
PORTREVISION?=	0
CATEGORIES?=	graphics multimedia
MASTER_SITES=	https://github.com/OpenImageIO/oiio/tarball/

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO graphics library

LICENSE?=	BSD

LIB_DEPENDS?=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		hdf5:${PORTSDIR}/science/hdf5 \
		opencv_legacy:${PORTSDIR}/graphics/opencv \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		webp:${PORTSDIR}/graphics/webp

USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio
GH_TAGNAME=	Release-${PORTVERSION}
GH_COMMIT=	db9df57

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS?=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DNOTHREADS:BOOL=OFF \
		-DUSE_TBB:BOOL=OFF

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-${GH_COMMIT}/src
MAKE_JOBS_SAFE=	yes

.if defined(OIIO_PYBIND)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt
PLIST=		${PKGDIR}/pkg-plist-pybind
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=ON
.else
PLIST=		${PKGDIR}/pkg-plist
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=OFF
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
# for gcc atomics we need to have an arch > i486
CFLAGS+=	-march=i586
.endif

.if ${OSVERSION} < 800000
IGNORE=	requires FreeBSD 8.0 or higher
.endif

post-install:
.if !defined(OIIO_PYBIND)
	cd ${PREFIX}/lib && ${LN} -sf libOpenImageIO.so.1.1 libOpenImageIO.so.1
.endif

.include <bsd.port.post.mk>
