PORTNAME=	libpqxx
DISTVERSION=	7.10.1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	New C++ interface for PostgreSQL
WWW=		http://pqxx.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang pkgconfig pgsql
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jtv

PLIST_SUB=	DISTVERSION=${DISTVERSION:R}

CMAKE_OFF=	BUILD_TEST
CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_SKIP_RPATH

.include <bsd.port.mk>
