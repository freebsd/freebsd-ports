PORTNAME=	utf8cpp
PORTVERSION=	3.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMESUFFIX=	3

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

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
