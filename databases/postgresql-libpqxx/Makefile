# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpqxx
PORTVERSION=	4.0.1
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	New C++ interface for PostgreSQL

LICENSE=	BSD3CLAUSE

CONFLICTS=	postgresql-libpqxx-3.* postgresql-libpqxx3-3.*
PORTSCOUT=	limit:^2\.

USE_PGSQL=	yes
USE_PYTHON_BUILD=	yes
USES=		gmake shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SOVERSION=	4
PLIST_SUB=	PORTVERSION=${PORTVERSION:R} \
		SOVERSION=${SOVERSION}
SHEBANG_FILES=	${WRKSRC}/tools/splitconfig

CONFIGURE_ARGS=	--enable-shared \
		--disable-dependency-tracking

post-install:
#	This is needed for ldconfig
	${LN} -sf libpqxx-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libpqxx.so.${SOVERSION}

.include <bsd.port.mk>
