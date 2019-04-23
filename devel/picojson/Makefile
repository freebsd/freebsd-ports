# $FreeBSD$

PORTNAME=	picojson
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Header file only JSON parser/serializer in C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kazuho

NO_ARCH=	yes
NO_BUILD=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
