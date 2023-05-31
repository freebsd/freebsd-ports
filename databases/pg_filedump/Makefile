PORTNAME=	pg_filedump
DISTVERSIONPREFIX= REL_
DISTVERSION=	14_1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Display formatted contents of a PostgreSQL heap, index, or control file
WWW=		https://github.com/df7cb/pg_filedump

LICENSE=	GPLv2+

USES=		gmake pgsql

MAKE_ARGS=	PG_LDFLAGS=-lintl
WANT_PGSQL=	lib server

PLIST_FILES=	bin/pg_filedump

GH_ACCOUNT=	df7cb
USE_GITHUB=	yes

.include <bsd.port.mk>
