PORTNAME=	linenoise-ng
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, portable readline replacement
WWW=		https://github.com/arangodb/linenoise-ng

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	arangodb

CFLAGS+=	-fPIC

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/linenoise.h	\
		lib/liblinenoise.so	\
		lib/liblinenoise.so.0

.include <bsd.port.mk>
