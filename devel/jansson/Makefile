PORTNAME=	jansson
DISTVERSION=	2.15.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/akheron/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/akheron/jansson/commit/
PATCHFILES=	c9e39c0154f7cdb2de6c33b8c4640a669fea0b58.patch:-p1 \
		fb012a005573435af7fef8d37df39c06b3c37c65.patch:-p1

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
