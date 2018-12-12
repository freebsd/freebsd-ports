# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpqxx
PORTVERSION=	3.1.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pqxx.org/download/software/${PORTNAME}/
PKGNAMEPREFIX=	postgresql-
PKGNAMESUFFIX=	3
DIST_SUBDIR=	postgresql

MAINTAINER=	20080111.freebsd.org@ab.ote.we.lv
COMMENT=	New C++ interface for PostgreSQL

LICENSE=	BSD3CLAUSE

CONFLICTS=	postgresql-libpqxx-2.* postgresql-libpqxx-[4-9].* \
		postgresql-libpqxx4-4.*
PORTSCOUT=	limit:^3\.

USES+=		gmake libtool pathfix pgsql pkgconfig python:2.7,build shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	tools/splitconfig

CONFIGURE_ARGS=	--enable-shared

.include <bsd.port.mk>
