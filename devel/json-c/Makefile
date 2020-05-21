# Created by: gno@yahoo-inc.com
# $FreeBSD$

PORTNAME=	json-c
PORTVERSION=	0.14
CATEGORIES=	devel
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON (JavaScript Object Notation) implementation in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c11 cpe

CMAKE_OFF=	BUILD_DOCUMENTATION
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS DISABLE_WERROR
TEST_TARGET=	test
USE_LDCONFIG=	yes

CPE_VENDOR=	json-c_project

post-install:
	${INSTALL_DATA} ${WRKSRC}/json_object_private.h ${STAGEDIR}${PREFIX}/include/json-c/

.include <bsd.port.mk>
