PORTNAME=	json-c
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON (JavaScript Object Notation) implementation in C
WWW=		https://github.com/json-c/json-c/wiki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c11 cpe

CMAKE_OFF=	BUILD_TESTING \
		DISABLE_BSYMBOLIC \
		DISABLE_JSON_PATCH \
		DISABLE_JSON_POINTER \
		DISABLE_STATIC_FPIC \
		DISABLE_THREAD_LOCAL_STORAGE \
		ENABLE_RDRAND \
		ENABLE_THREADING \
		OVERRIDE_GET_RANDOM_SEED
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		DISABLE_EXTRA_LIBS \
		DISABLE_WERROR
USE_LDCONFIG=	yes

CPE_VENDOR=	json-c_project

.include <bsd.port.mk>
