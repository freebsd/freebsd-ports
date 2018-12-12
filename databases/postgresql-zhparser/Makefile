# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	zhparser
PORTVERSION=	0.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL extension for full-text search of Chinese

LICENSE=	PostgreSQL

LIB_DEPENDS=	libscws.so:textproc/scws

USES=		gmake pgsql:9.2+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	amutu

WANT_PGSQL=	server

MAKE_ENV=	SCWS_HOME=${PREFIX}

PLIST_FILES=	lib/postgresql/zhparser.so \
		share/postgresql/extension/zhparser--1.0.sql \
		share/postgresql/extension/zhparser--unpackaged--1.0.sql \
		share/postgresql/extension/zhparser.control \
		share/postgresql/tsearch_data/dict.utf8.xdb \
		share/postgresql/tsearch_data/rules.utf8.ini

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/zhparser.so

.include <bsd.port.mk>
