# New ports collection makefile for:	OpenImageIO
# Date created:			21 March 2012
# Whom:					Shane Ambler
#
# $FreeBSD$
#

PORTNAME=	openimageio
PORTVERSION=	1.0.9
CATEGORIES=	graphics multimedia
MASTER_SITES=	https://github.com/OpenImageIO/oiio/tarball/
DISTNAME=	Release-${PORTVERSION}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO graphics library

LICENSE=	BSD

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		hdf5:${PORTSDIR}/science/hdf5 \
		opencv_legacy:${PORTSDIR}/graphics/opencv \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		tbb:${PORTSDIR}/devel/tbb \
		webp:${PORTSDIR}/graphics/webp

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

FETCH_ARGS=	-pRr
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DUSE_PYTHON:BOOL=OFF \
		-DUSE_TBB:BOOL=ON
LDFLAGS+=	-ltbb
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-0d48631/src
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DOCS IMAGEVIEWER THREADS
OPTIONS_DEFAULT=	DOCS IMAGEVIEWER THREADS

IMAGEVIEWER_DESC=	Build image viewer

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

.if ${PORT_OPTIONS:MTHREADS}
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
