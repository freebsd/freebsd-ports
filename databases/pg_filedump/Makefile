# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pg_filedump
PORTVERSION=	14.0
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Display formatted contents of a PostgreSQL heap, index, or control file

LICENSE=	GPLv2+

USES=		gmake pgsql

MAKE_ARGS=	PG_LDFLAGS=-lintl
WANT_PGSQL=	lib server

PLIST_FILES=	bin/pg_filedump

GH_ACCOUNT=	df7cb
GH_TAGNAME=	REL_${PORTVERSION:R}_${PORTVERSION:E}
USE_GITHUB=	yes

.include <bsd.port.mk>
