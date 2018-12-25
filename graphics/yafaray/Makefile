# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	yafaray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0-11
DISTVERSIONSUFFIX=	-g1c0b43a
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Montecarlo raytracing engine

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_EASON=	assembly is only for amd64 and i386, but it breaks on i386: https://github.com/YafaRay/Core/issues/111

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libHalf.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libopencv_photo.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake gnome jpeg
USE_GITHUB=	yes
GH_ACCOUNT=	YafaRay
GH_PROJECT=	Core
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_OFF=	WITH_YAF_PY_BINDINGS

OPTIONS_DEFINE=	DOCS QT
OPTIONS_SUB=	yes

QT_DESC=	Enable Qt Gui build
QT_USES=	qt:4
QT_CMAKE_BOOL=	WITH_QT
QT_USE=		QT=corelib,gui,moc_build,qmake_build,rcc_build,uic_build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSES

.include <bsd.port.mk>
