PORTNAME=	re
DISTVERSIONPREFIX=	v
DISTVERSION=	3.24.0
CATEGORIES=	audio devel

MAINTAINER=	herbert@gojira.at
COMMENT=	Library for real-time comms with async IO support
WWW=		https://github.com/baresip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing ssl
USE_GITHUB=	yes
GH_ACCOUNT=	baresip
USE_LDCONFIG=	yes

CMAKE_TESTING_TARGET=	retest

.include <bsd.port.mk>
