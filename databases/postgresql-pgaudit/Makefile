PORTNAME=		pgaudit
#DISTVERSIONPREFIX=	v
PORTVERSION=	16.0
CATEGORIES=		databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S|.||}-

MAINTAINER=		gehaowu@bitmoe.com
COMMENT=		PostgreSQL Audit Extension
WWW=			https://www.pgaudit.org/

LICENSE=		PostgreSQL

USES=			gmake pgsql:16+
WANT_PGSQL=		server
USE_GITHUB=		yes
GH_ACCOUNT=		pgaudit

MAKE_ENV=		USE_PGXS=1

PLIST_FILES=	lib/postgresql/pgaudit.so \
		share/postgresql/extension/pgaudit--16.0.sql \
		share/postgresql/extension/pgaudit.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgaudit.so

.include <bsd.port.mk>
