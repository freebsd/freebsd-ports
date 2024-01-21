PORTNAME=	libasyncplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	1
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

STATIC_DESC=	Build static library

CMAKE_ON=	ASYNCXX_BUILD_SHARED

STATIC_CMAKE_BOOL=	ASYNCXX_BUILD_STATIC

.include <bsd.port.mk>
