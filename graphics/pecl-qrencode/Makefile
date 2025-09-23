PORTNAME=	qrencode
PORTVERSION=	0.11
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	graphics pear

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PECL extension for generate qrcode
WWW=		https://github.com/embark-systems/pecl-qrencode

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libqrencode.so:graphics/libqrencode \
		libpng.so:graphics/png

USES=		php:pecl
USE_GITHUB=	yes
GH_ACCOUNT=	embark-systems
GH_PROJECT=	pecl-qrencode

.include <bsd.port.mk>
