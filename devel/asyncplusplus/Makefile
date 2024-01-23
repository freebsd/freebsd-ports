PORTNAME=	asyncplusplus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	1 # 1 is for the added STATIC option
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Async++ concurrency framework for C++11
WWW=		https://github.com/Amanieu/asyncplusplus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Amanieu
GH_TAGNAME=	627e0520d1b22c075f65fb7abc6269377e3a4c40 # include the PR https://github.com/Amanieu/asyncplusplus/pull/57 to build the shared library

CMAKE_ON=	ASYNCXX_BUILD_SHARED

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes

STATIC_DESC=		Build static library
STATIC_CMAKE_BOOL=	ASYNCXX_BUILD_STATIC

.include <bsd.port.mk>
