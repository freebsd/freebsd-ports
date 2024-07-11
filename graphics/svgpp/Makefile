PORTNAME=	svgpp
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C++ header-only parsers for various SVG syntaxes
WWW=		http://svgpp.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${CP} -a ${WRKSRC}/include/ ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
