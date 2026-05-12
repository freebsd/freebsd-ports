PORTNAME=	tinycbor
PORTVERSION=	7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Concise Binary Object Representation (CBOR) library
WWW=		https://github.com/intel/tinycbor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcjson.so:devel/libcjson

USES=		cmake:testing compiler:c++20-lang localbase:ldflags pkgconfig

CMAKE_OFF=	WITH_FREESTANDING
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_TOOLS \
		WITH_CBOR2JSON \
		WITH_FLOATING_POINT \
		WITH_VALGRIND

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	intel
USE_GITHUB=	yes

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/tools/json2cbor/json2cbor ${STAGEDIR}${PREFIX}/bin/json2cbor

.include <bsd.port.mk>
