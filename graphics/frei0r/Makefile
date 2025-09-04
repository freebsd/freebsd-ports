PORTNAME=	frei0r
DISTVERSIONPREFIX=	v
DISTVERSION=	${FREI0R_VERSION}
PORTREVISION?=	0
CATEGORIES=	graphics

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Minimalistic plugin API for video effects
WWW=		https://frei0r.dyne.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dyne

.if defined(EXTRA_PLUGINS)
RUN_DEPENDS=	frei0r>=${FREI0R_VERSION}:graphics/frei0r
.  if ${EXTRA_PLUGINS:tl} == "cairo"
USES+=		gnome
USE_GNOME+=	cairo

CMAKE_ON=	WITHOUT_GAVL \
		WITHOUT_OPENCV
CMAKE_OFF=	WITHOUT_CAIRO
.  elif ${EXTRA_PLUGINS:tl} == "gavl"
LIB_DEPENDS+=	libgavl.so:multimedia/gavl

CMAKE_ON=	WITHOUT_CAIRO \
		WITHOUT_OPENCV
CMAKE_OFF=	WITHOUT_GAVL
.  elif ${EXTRA_PLUGINS:tl} == "opencv"
LIB_DEPENDS+=	libopencv_core.so:graphics/opencv

CMAKE_ON=	WITHOUT_CAIRO \
		WITHOUT_GAVL
CMAKE_OFF=	WITHOUT_OPENCV
.  endif
.else
CMAKE_ON=	WITHOUT_CAIRO \
		WITHOUT_GAVL \
		WITHOUT_OPENCV
CMAKE_OFF=	BUILD_EXTRA_PLUGINS
.endif

.include "version.mk"
.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# work around regression seen in GCC 10 but not in GCC 9:
# src/filter/elastic_scale/elastic_scale.cpp:152: error: ISO C++ forbids initialization of member 'm_transformationCalculations'
CFLAGS+=	-Wno-error
CXXFLAGS+=	-Wno-error
.endif

.include <bsd.port.post.mk>
