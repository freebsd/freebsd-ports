PORTNAME=	pg_filedump
DISTVERSIONPREFIX= REL_
DISTVERSION=	17_0
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Display formatted contents of a PostgreSQL heap, index, or control file
WWW=		https://github.com/df7cb/pg_filedump

LICENSE=	GPLv2+

USES=		gettext-runtime gmake pgsql

MAKE_ARGS=	PG_LDFLAGS=-lintl
WANT_PGSQL=	lib server

PLIST_FILES=	bin/pg_filedump

GH_ACCOUNT=	df7cb
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pg_filedump

.include <bsd.port.mk>
