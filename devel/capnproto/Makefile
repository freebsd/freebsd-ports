PORTNAME=	capnproto
DISTVERSION=	0.10.3
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/
DISTNAME=	${PORTNAME}-c++-${DISTVERSION}

MAINTAINER=	felix@userspace.com.au
COMMENT=	Serialization/RPC system
WWW=		https://capnproto.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang cpe pathfix ssl
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

CONFLICTS_INSTALL=	capnproto080

PLIST_SUB=	DISTVERSION="${DISTVERSION}"

.include <bsd.port.mk>
