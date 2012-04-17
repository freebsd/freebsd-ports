# New ports collection makefile for:	OpenImageIO
# Date created:			21 March 2012
# Whom:					Shane Ambler
#
# $FreeBSD$
#

PORTNAME=	openimageio
PORTVERSION=	1.0.2
CATEGORIES=	graphics multimedia
MASTER_SITES=	https://github.com/OpenImageIO/oiio/tarball/
DISTNAME=	Release-${PORTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO graphics library

LICENSE=	BSD

LIB_DEPENDS=	openjpeg:${PORTSDIR}/graphics/openjpeg \
		opencv_legacy.2:${PORTSDIR}/graphics/opencv \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tbb.4:${PORTSDIR}/devel/tbb \
		webp.2:${PORTSDIR}/graphics/webp \
		hdf5:${PORTSDIR}/science/hdf5

FETCH_ARGS=	-pRr
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DUSE_TBB:BOOL=ON
LDFLAGS+=	-ltbb
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-1595432/src
MAKE_JOBS_SAFE=	yes

OPTIONS=	IMAGEVIEWER "Build image viewer" on \
		PYTHON "Python bindings"  on \
		NOTHREADS "Disable thread support" off

post-patch:
	@${REINPLACE_CMD} 's|lib/python|lib/${PYTHON_VERSION}|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.options.mk>

.if defined(WITH_IMAGEVIEWER)
USE_GL=		glew
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl qmake_build moc_build rcc_build uic_build
CMAKE_ARGS+=	-DUSE_QT:BOOL=ON -DUSE_OPENGL:BOOL=ON
CMAKE_ENV+=	QTDIR=${QT_PREFIX} QT_INCLUDES=${QT_INCDIR}
PLIST_SUB+=	IMAGEVIEWER=""
.else
CMAKE_ARGS+=	-DUSE_OPENGL:BOOL=OFF -DUSE_QT:BOOL=OFF
PLIST_SUB+=	IMAGEVIEWER="@comment "
.endif

.if defined(WITH_PYTHON)
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=ON
USE_PYTHON=	2.6+
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
PLIST_SUB+=	PYTHON_BIND=""
.else
CMAKE_ARGS+=	-DUSE_PYTHON:BOOL=OFF
PLIST_SUB+=	PYTHON_BIND="@comment "
.endif

.if defined(WITH_NOTHREADS)
CMAKE_ARGS+=	-DNOTHREADS:BOOL=ON
.else
CMAKE_ARGS+=	-DNOTHREADS:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${OSVERSION} < 803000
USE_GCC=	4.6+
.endif

.if ${OSVERSION} < 800000
IGNORE=	requires FreeBSD 8.0 or higher
.endif

post-install:
	cd ${PREFIX}/lib && ${LN} -sf libOpenImageIO.so.1.0 libOpenImageIO.so.1

.include <bsd.port.post.mk>
