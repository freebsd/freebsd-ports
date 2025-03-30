PORTNAME=	jansson
DISTVERSION=	2.14.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/akheron/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding, decoding, and manipulating JSON data
WWW=		https://github.com/akheron/jansson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash>=0:shells/bash

USES=		cmake:testing cpe tar:bzip2 pathfix shebangfix
CPE_VENDOR=	jansson_project
SHEBANG_FILES=	scripts/clang-format scripts/clang-format-check
USE_LDCONFIG=	yes

CMAKE_TESTING_OFF=	JANSSON_WITHOUT_TESTS

CMAKE_OFF=	JANSSON_BUILD_DOCS
CMAKE_ON=	JANSSON_BUILD_SHARED_LIBS \
		JANSSON_WITHOUT_TESTS

.include <bsd.port.mk>
