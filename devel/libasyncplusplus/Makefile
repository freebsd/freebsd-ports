PORTNAME=	libasyncplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	peter@flytrace.com
COMMENT=	Lightweight concurrency framework for C++
WWW=		https://github.com/Amanieu/asyncplusplus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake compiler:c++11-lang

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Amanieu
GH_PROJECT=	asyncplusplus

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=	yes

STATIC_DESC=	Build static library instead of shared

STATIC_CMAKE_BOOL_OFF=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
