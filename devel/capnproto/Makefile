# Created by: Felix Hanley

PORTNAME=	capnproto
DISTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/
DISTNAME=	${PORTNAME}-c++-${DISTVERSION}

MAINTAINER=	felix@userspace.com.au
COMMENT=	Serialization/RPC system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang cpe pathfix ssl
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	capnproto080

CMAKE_OFF=	BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	DISTVERSION="${DISTVERSION}"

.include <bsd.port.mk>
