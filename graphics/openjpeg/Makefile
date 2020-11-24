# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake>=3:devel/cmake
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake cpe pkgconfig

USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} VER=${PORTVERSION:R}

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

.include <bsd.port.mk>
