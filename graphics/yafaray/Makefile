# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	yafaray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.4
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Montecarlo raytracing engine

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	assembly is only for amd64 and i386, but it breaks on i386: https://github.com/YafaRay/Core/issues/111

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libHalf.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libopencv_photo.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake gnome jpeg
USE_GITHUB=	yes
GH_ACCOUNT=	YafaRay
GH_PROJECT=	Core
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

LDFLAGS+=	-pthread # because build on 13 (head) was failing: ld: error: src/yafraycore/libyafaray_v3_core.so: undefined reference to pthread_create

CMAKE_OFF=	WITH_YAF_PY_BINDINGS

OPTIONS_DEFINE=	DOCS QT
OPTIONS_SUB=	yes

QT_DESC=	Enable Qt Gui build
QT_USES=	qt:5
QT_CMAKE_BOOL=	WITH_QT
QT_USE=		QT=core,gui,widgets,qmake_build,buildtools_build,qmake_build

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSES

.include <bsd.port.mk>
