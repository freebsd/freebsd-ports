PORTNAME=	pg_dirtyread
PORTVERSION=	2.6
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read dead but unvacuumed tuples from a PostgreSQL relation
WWW=		https://github.com/df7cb/pg_dirtyread

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql

LLD_UNSAFE=	yes
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	df7cb

PLIST_FILES=	lib/postgresql/pg_dirtyread.so \
		share/postgresql/extension/pg_dirtyread--1.0.sql \
		share/postgresql/extension/pg_dirtyread--1.0--2.sql \
		share/postgresql/extension/pg_dirtyread--2.sql \
		share/postgresql/extension/pg_dirtyread.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_dirtyread.so

.include <bsd.port.mk>
