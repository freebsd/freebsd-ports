PORTNAME=	libb64
DISTVERSION=	2.0.0-15
CATEGORIES=	converters mail

MAINTAINER=	ismail.yenigul@surgate.com
COMMENT=	Library for fast Base64 encoding and decoding
WWW=		https://github.com/stefantalpalaru/libb64

LICENSE=	MIT

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	stefantalpalaru
GH_TAGNAME=	382c274

CMAKE_TESTING_ON=	LIBB64_BUILD_EXAMPLES LIBB64_ENABLE_TESTS
CMAKE_OFF=	LIBB64_BUILD_EXAMPLES LIBB64_BUILD_PROGRAMS LIBB64_ENABLE_TESTS
CMAKE_ON=	LIBB64_SHARED

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libb64.so ${STAGEDIR}${PREFIX}/lib/libb64.so.0

.include <bsd.port.mk>
