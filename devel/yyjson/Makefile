PORTNAME=	yyjson
DISTVERSION=	0.13.0
CATEGORIES=	devel

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Fastest JSON library in C
WWW=		https://github.com/ibireme/yyjson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	ibireme

USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	YYJSON_BUILD_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
