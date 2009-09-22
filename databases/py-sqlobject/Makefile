# Ports collection makefile for:	py-sqlobject
# Date created:				24 June 2004
# Whom:					"Choe, Cheng-Dae" whitekid
#
# $FreeBSD$
#

PORTNAME=	sqlobject
PORTVERSION=	0.11.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A python object for manipulation with SQL table row

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	SQLObject
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's

PORTDOCS=	*

OPTIONS=	MYSQL	"MySQL supports" off \
		PGSQL	"PostgreSQL Supports" off \
		SQLITE	"SQLite Supports" off \
		MSSQL	"MSSQL Supports" off

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

PYSQLOBJECT_EGG=	SQLObject-${SQLOBJECTVER}-py${PYTHONVER}.egg
PYFORMENCODE_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-formencode/Makefile -V PYFORMENCODE_EGG

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/${PYFORMENCODE_EGG}:${PORTSDIR}/www/py-formencode

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.endif

.if defined(WITH_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
.endif

.if defined(WITH_MSSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

# currently FireBird, MaxDB(SAP), Sybase, ADODB are not supported

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
