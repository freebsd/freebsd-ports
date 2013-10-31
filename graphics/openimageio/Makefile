# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openimageio
PORTVERSION=	1.2.2
PORTREVISION?=	1
CATEGORIES?=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	OpenImageIO graphics library

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio
GH_TAGNAME=	Release-${PORTVERSION}
GH_COMMIT=	f9d8f1b
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-${GH_COMMIT}/src

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

USES=		cmake:outsource
CMAKE_ARGS=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DNOTHREADS:BOOL=OFF \
		-DUSE_TBB:BOOL=OFF \
		-DSTOP_ON_WARNING:BOOL=OFF

OPTIONS_DEFINE=		DOCS IMAGEVIEWER OCIO
OPTIONS_DEFAULT=	IMAGEVIEWER OCIO
OPTIONS_SUB=		yes

IMAGEVIEWER_DESC=	Build image viewer
OCIO_DESC=		Colour management support

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libhdf5.so:${PORTSDIR}/science/hdf5-18 \
		libopencv_legacy.so:${PORTSDIR}/graphics/opencv \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg \
		libwebp.so:${PORTSDIR}/graphics/webp
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=OFF -DOIIO_BUILD_TOOLS:BOOL=ON
.else
LIB_DEPENDS=	libOpenImageIO.so:${PORTSDIR}/graphics/openimageio \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs
USE_PYTHON=	2.6+
PLIST=		${PKGDIR}/pkg-plist-pybind
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=ON -DOIIO_BUILD_TOOLS:BOOL=OFF
.endif

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
.else
CMAKE_ARGS+=	-DUSE_OPENGL:BOOL=OFF -DUSE_QT:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MOCIO}
CMAKE_ARGS+=	-DUSE_OCIO:BOOL=ON
LIB_DEPENDS+=	libOpenColorIO.so:${PORTSDIR}/graphics/opencolorio
.else
CMAKE_ARGS+=	-DUSE_OCIO:BOOL=OFF
.endif

post-install:
.if ${SLAVE_PORT} == no
	${LN} -sf libOpenImageIO.so.1.2 ${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.1
.endif

.include <bsd.port.mk>
