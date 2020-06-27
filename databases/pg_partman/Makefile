# $FreeBSD$

PORTNAME=	pg_partman
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
CATEGORIES=	databases

MAINTAINER=	lacey.leanne@gmail.com
COMMENT=	PostgreSQL Partition Manager

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:databases/py-psycopg2

USES=		gmake pgsql:9.4+ python uidfix shebangfix
LLD_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	keithf4

WANT_PGSQL=	server
SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# With PG11+ some scripts are only installed when they are common to
# all PG versions.
.if ${PGSQL_VER:R} < 11
PLIST_SUB+=	OLDPG=""
.else
PLIST_SUB+=	OLDPG="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_partman_bgw.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension/*.md ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/postgresql

.include <bsd.port.post.mk>
