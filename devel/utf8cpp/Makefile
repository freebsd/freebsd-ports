PORTNAME=	utf8cpp
PORTVERSION=	4.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, portable, lightweight library for handling UTF-8 strings
WWW=		https://github.com/nemtrif/utfcpp

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

CMAKE_ON=	UTF8_INSTALL
CMAKE_OFF=	UTF8_SAMPLES UTF8_TESTS

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nemtrif
GH_PROJECT=	utfcpp

.include <bsd.port.mk>
