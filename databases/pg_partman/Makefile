# $FreeBSD$

PORTNAME=	pg_partman
DISTVERSION=	3.1.0
CATEGORIES=	databases

MAINTAINER=	lacey.leanne@gmail.com
COMMENT=	PostgreSQL Partition Manager

LICENSE=	PostgreSQL

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:databases/py-psycopg2

USES=		gmake pgsql:9.4+ python uidfix shebangfix
WANT_PGSQL=	server
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_TUPLE=	keithf4:${PORTNAME}:v${PORTVERSION}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension/*.md ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql/extension
	${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql

.include <bsd.port.mk>
