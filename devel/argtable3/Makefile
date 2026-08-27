PORTNAME=	argtable3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ANSI C library that parses GNU-style command-line options
WWW=		https://www.argtable.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	argtable

CMAKE_OFF=	ARGTABLE3_ENABLE_TESTS \
		ARGTABLE3_ENABLE_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS

post-patch:
	${REINPLACE_CMD} '66d' ${WRKSRC}/tools/build

.include <bsd.port.mk>
