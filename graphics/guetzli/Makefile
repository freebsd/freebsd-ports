# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	guetzli
PORTVERSION=	1.0.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	yuri@rawbw.com
COMMENT=	Perceptual JPEG encoder

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		compiler:c++11-lib gmake pkgconfig
PLIST_FILES=	bin/guetzli
MAKE_FLAGS=	verbose=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Release/guetzli ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
