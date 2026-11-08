PORTNAME=	json-c
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON (JavaScript Object Notation) implementation in C
WWW=		https://github.com/json-c/json-c/wiki \
		https://json-c.github.io/json-c/ \
		https://github.com/json-c/json-c

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
		NEWLOCALE_NEEDS_FREELOCALE \
		OVERRIDE_GET_RANDOM_SEED
CMAKE_ON=	BUILD_APPS \
		BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		DISABLE_EXTRA_LIBS \
		DISABLE_WERROR
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	81092b3

.include <bsd.port.mk>
