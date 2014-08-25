# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpqxx
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/${PORTNAME}/
PKGNAMEPREFIX=	postgresql-
PKGNAMESUFFIX=	3
DIST_SUBDIR=	postgresql

MAINTAINER=	20080111.freebsd.org@ab.ote.we.lv
COMMENT=	New C++ interface for PostgreSQL

CONFLICTS=	postgresql-libpqxx-[2-4].*
PORTSCOUT=	limit:^2\.

USES+=		gmake libtool pgsql pkgconfig shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_PYTHON_BUILD=	yes
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	tools/splitconfig
python_CMD=	${PYTHON_CMD}

CONFIGURE_ARGS=	--enable-shared

.include <bsd.port.mk>
