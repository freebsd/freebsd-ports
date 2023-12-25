PORTNAME=	utf8cpp
PORTVERSION=	4.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, portable, lightweight library for handling UTF-8 strings
WWW=		https://github.com/nemtrif/utfcpp

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nemtrif
GH_PROJECT=	utfcpp

CONFLICTS_INSTALL=	utf8cpp3

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/utf8cpp/
	cd ${WRKSRC}/source/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/utf8cpp/

.include <bsd.port.mk>
