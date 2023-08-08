PORTNAME=	perceptualdiff
PORTVERSION=	2.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that compares two images
WWW=		https://github.com/myint/perceptualdiff

LICENSE=	GPLv2

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage

PLIST_FILES=	bin/perceptualdiff

USE_GITHUB=	yes
GH_ACCOUNT=	myint

USES=		cmake
.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++0x
.endif

.include <bsd.port.mk>
