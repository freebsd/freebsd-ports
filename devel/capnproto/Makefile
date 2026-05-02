PORTNAME=	capnproto
DISTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/
DISTNAME=	${PORTNAME}-c++-${DISTVERSION}

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Serialization/RPC system
WWW=		https://capnproto.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang cpe pathfix ssl
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	capnproto1

PLIST_SUB=	DISTVERSION="${DISTVERSION}"

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
