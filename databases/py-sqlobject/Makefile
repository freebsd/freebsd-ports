# Ports collection makefile for:	py-sqlobject
# Date created:				24 June 2004
# Whom:					"Choe, Cheng-Dae" whitekid
#
# $FreeBSD$
#

PORTNAME=	sqlobject
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/S/SQLObject/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A python object for manipulation with SQL table row

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*

OPTIONS=	MYSQL	"MySQL supports" off \
		PGSQL	"PostgreSQL Supports" off \
		SQLITE	"SQLite Supports" off

.include <bsd.port.pre.mk>

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/formencode/__init__.py:${PORTSDIR}/www/py-formencode

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if defined(WITH_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
.endif

# currently FireBird, MaxDB(SAP), Sybase, MSSQL, ADODB are not supported

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
