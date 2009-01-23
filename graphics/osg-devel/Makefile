# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	2.6.1
PORTREVISION=		1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/downloads/developer_releases/ \
		http://mirror.amdmi3.ru/
DISTNAME=	OpenSceneGraph-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_ZIP=	yes
USE_CMAKE=	yes
USE_GL=		gl glu
WANT_SDL=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	OSG_VERSION=2.6.1 OSG_SHLIBVER=48

OPTIONS=	CURL		"Support for cURL"		off \
		FREETYPE	"Support for FreeType"		on \
		GDAL		"Support for GDAL"		off \
		GIF		"Support for libungif"		on \
		INVENTOR	"Support for SGI OpenInventor"	off \
		JASPER		"Support for JPEG2000"		off \
		OPENVRML 	"Support for OpenVRML"		off \
		XINE		"Support for Xine"		off

.include <bsd.port.pre.mk>

# Gui toolkits (FOX, WX, QT, FLTK, SDL, GLUT) are only needed for
# examples which are not installed, so leave them as is (autodetected)
FORCE_IGNORE=	COLLADA	Performer
FORCE_REQUIRE=	JPEG PNG TIFF ZLIB Threads OpenGL X11

.if defined(WITH_CURL)
FORCE_REQUIRE+=	CURL
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
FORCE_IGNORE+=	CURL
PLIST_SUB+=	CURL="@comment "
.endif

.if !defined(WITHOUT_FREETYPE)
FORCE_REQUIRE+=	FreeType
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
PLIST_SUB+=	FREETYPE=""
.else
FORCE_IGNORE+=	FreeType
PLIST_SUB+=	FREETYPE="@comment "
.endif

.if defined(WITH_GDAL)
FORCE_REQUIRE+=	GDAL
LIB_DEPENDS+=	gdal.13:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	GDAL=""
.else
FORCE_IGNORE+=	GDAL
PLIST_SUB+=	GDAL="@comment "
.endif

.if defined(WITH_GIF)
FORCE_REQUIRE+=	GIFLIB
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
PLIST_SUB+=	GIF=""
.else
FORCE_IGNORE+=	GIFLIB
PLIST_SUB+=	GIF="@comment "
.endif

.if defined(WITH_INVENTOR)
FORCE_REQUIRE+=	Inventor
LIB_DEPENDS+=	Inventor:${PORTSDIR}/graphics/inventor
PLIST_SUB+=	INVENTOR=""
.else
FORCE_IGNORE+=	Inventor
PLIST_SUB+=	INVENTOR="@comment "
.endif

.if defined(WITH_JASPER)
FORCE_REQUIRE+=	Jasper
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
PLIST_SUB+=	JASPER=""
.else
FORCE_IGNORE+=	Jasper
PLIST_SUB+=	JASPER="@comment "
.endif

.if defined(WITH_OPENVRML)
FORCE_REQUIRE+=	OpenVRML
LIB_DEPENDS+=	openvrml.8:${PORTSDIR}/www/openvrml
PLIST_SUB+=	OPENVRML=""
.else
FORCE_IGNORE+=	OpenVRML
PLIST_SUB+=	OPENVRML="@comment "
.endif

.if defined(WITH_XINE)
FORCE_REQUIRE+=	Xine
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.else
FORCE_IGNORE+=	Xine
PLIST_SUB+=	XINE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"64"|""|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|cpu_set_t|cpuset_t|g' \
		${WRKSRC}/src/OpenThreads/pthreads/CMakeLists.txt \
		${WRKSRC}/src/OpenThreads/pthreads/PThread.c++
.for p in ${FORCE_REQUIRE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|)$$| REQUIRED&|' \
		${WRKSRC}/CMakeLists.txt
.endfor
.for p in ${FORCE_IGNORE}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*${p}/ s|^|#|' \
		${WRKSRC}/CMakeLists.txt
.endfor

.include <bsd.port.post.mk>
