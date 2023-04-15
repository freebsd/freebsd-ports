PORTNAME=	pg_partman
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.0
CATEGORIES=	databases

MAINTAINER=	lacey.leanne@gmail.com
COMMENT=	PostgreSQL Partition Manager
WWW=		https://github.com/keithf4/pg_partman

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:databases/py-psycopg2

USES=		cpe gmake pgsql:11+ python uidfix shebangfix
CPE_VENDOR=	pgxn

USE_GITHUB=	yes
GH_ACCOUNT=	keithf4

WANT_PGSQL=	server
SHEBANG_GLOB=	*.py

LLD_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_partman_bgw.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension/*.md ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/postgresql

.include <bsd.port.mk>
