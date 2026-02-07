PORTNAME=	hiredis
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0-15
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minimalistic C client library for the Redis database
WWW=		https://github.com/redis/hiredis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe ssl
CPE_VENDOR=	redislabs

USE_GITHUB=	yes
GH_ACCOUNT=	redis
GH_TAGNAME=	7ab6b82

USE_LDCONFIG=	yes

CMAKE_ON=	DISABLE_TESTS ENABLE_SSL
CMAKE_OFF=	ENABLE_NUGET

.include <bsd.port.mk>
