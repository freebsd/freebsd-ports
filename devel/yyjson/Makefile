PORTNAME=	yyjson
DISTVERSION=	0.12.0
CATEGORIES=	devel

PATCH_SITES=	https://github.com/ibireme/yyjson/commit/
PATCHFILES=	878d5da9b6c0352c2601bd6c244c0ef994ee1c24.patch:-p1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Fastest JSON library in C 
WWW=		https://github.com/ibireme/yyjson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	ibireme

CMAKE_TESTING_ON=	YYJSON_BUILD_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
