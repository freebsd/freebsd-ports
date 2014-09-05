# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpqxx
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/libpqxx/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	New C++ interface for PostgreSQL

LICENSE=	BSD3CLAUSE

CONFLICTS=	postgresql-libpqxx-3.* postgresql-libpqxx3-3.*
PORTSCOUT=	limit:^2\.

USE_PYTHON_BUILD=	yes
USES+=		gmake libtool pgsql shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION:R}
SHEBANG_FILES=	${WRKSRC}/tools/splitconfig
python_CMD=	${PYTHON_CMD}

CONFIGURE_ARGS=	--enable-shared \
		--disable-dependency-tracking

.include <bsd.port.mk>
