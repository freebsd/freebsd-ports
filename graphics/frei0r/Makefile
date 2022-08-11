PORTNAME=	frei0r
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	plugins-
PORTREVISION?=	0
CATEGORIES=	graphics
MASTER_SITES?=	https://files.dyne.org/frei0r/releases/

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Minimalistic plugin API for video effects

.if !defined(BUILDING_FREI0R_METAPORT)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake compiler:c++11-lang pkgconfig

.if defined(BUILDING_FREI0R_OPENCV) && defined(BUILDING_FREI0R_GAVL)
IGNORE=		cannot build OpenCV and gavl plugins simultaneously
.endif

.if defined(BUILDING_FREI0R_OPENCV) || defined(BUILDING_FREI0R_GAVL)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-frei0r-plugins

USES+=		localbase
.endif

.if defined(BUILDING_FREI0R_OPENCV)
PORTREVISION=	0
COMMENT=	Frei0r OpenCV plugins
PKGNAMESUFFIX=	-plugins-opencv
LIB_DEPENDS+=	libopencv_core.so:graphics/opencv \
		libopencv_video.so:graphics/opencv
FREI0R_PLUGINS=	facebl0r facedetect

CMAKE_ARGS+=	-DWITHOUT_OPENCV:BOOL=OFF \
		-DWITHOUT_GAVL:BOOL=ON
.elif defined(BUILDING_FREI0R_GAVL)
PORTREVISION=	0
COMMENT=	Frei0r gavl plugins
PKGNAMESUFFIX=	-plugins-gavl
LIB_DEPENDS+=	libgavl.so:multimedia/gavl
FREI0R_PLUGINS=	rgbparade scale0tilt vectorscope

CMAKE_ARGS+=	-DWITHOUT_OPENCV:BOOL=ON \
		-DWITHOUT_GAVL:BOOL=OFF
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt

USES+=		gnome
USE_GNOME=	cairo

CMAKE_ARGS+=	-DWITHOUT_OPENCV:BOOL=ON \
		-DWITHOUT_GAVL:BOOL=ON

.endif # !defined(BUILDING_FREI0R_OPENCV) && !defined(BUILDING_FREI0R_GAVL)

.if defined(FREI0R_PLUGINS)
PLIST=		${WRKSRC}/PLIST
. for FILE in ${FREI0R_PLUGINS}
PLIST_FILES+=	lib/frei0r-1/${FILE}.so
. endfor
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# work around regression seen in GCC 10 but not in GCC 9:
# src/filter/elastic_scale/elastic_scale.cpp:152: error: ISO C++ forbids initialization of member 'm_transformationCalculations'
CFLAGS+=	-Wno-error
CXXFLAGS+=	-Wno-error
.endif

.include <bsd.port.post.mk>

.endif # !defined(BUILDING_FREI0R_METAPORT)
