PORTNAME=	msgpack
PORTVERSION=	5.0.0
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel
PKGNAMESUFFIX=	-cxx

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Efficient binary serialization protocol (C++ version)
WWW=		https://msgpack.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake pathfix
USE_GITHUB=	yes
GH_PROJECT=	msgpack-c
NO_ARCH=	yes

CMAKE_OFF=	MSGPACK_BUILD_EXAMPLES MSGPACK_USE_BOOST

.include <bsd.port.mk>
