# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcbor
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CBOR protocol implementation for C and others

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcjson.so:devel/libcjson

USES=		cmake

CMAKE_OFF=	CBOR_CUSTOM_ALLOC COVERAGE HUGE_FUZZ PRINT_FUZZ SANE_MALLOC SANITIZE WITH_EXAMPLES WITH_TESTS
CMAKE_ON=	CBOR_PRETTY_PRINTER

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	PJK
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-flto||; /subdirs(examples)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
