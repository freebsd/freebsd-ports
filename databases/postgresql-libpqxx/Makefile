PORTNAME=	libpqxx
PORTVERSION=	7.9.2
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	New C++ interface for PostgreSQL
WWW=		http://pqxx.org/

LICENSE=	BSD3CLAUSE

CONFLICTS=	postgresql-libpqxx-[1-5].* postgresql-libpqxx3-3.* \
		postgresql-libpqxx4-4.*

USES=		compiler:c++17-lang gmake libtool pathfix pgsql python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jtv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	${WRKSRC}/tools/splitconfig.py
INSTALL_TARGET=	install-strip
PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

CONFIGURE_ARGS=	--enable-shared \
		--disable-documentation \
		--disable-dependency-tracking
CXXFLAGS+=	-std=c++17

.include <bsd.port.mk>
