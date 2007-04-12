# Ports collection makefile for:	py-sqlobject
# Date created:				24 June 2004
# Whom:					"Choe, Cheng-Dae" whitekid
#
# $FreeBSD$
#

PORTNAME=	sqlobject
PORTVERSION=	0.8.2
CATEGORIES=	databases python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/S/SQLObject/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A python object for manipulation with SQL table row

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
SQLOBJECTVER?=	${PORTVERSION}
PYTHONVER?=	${PYTHON_VERSION:S/^python//}
PLIST_SUB=	PYSQLOBJECT_EGG=${PYSQLOBJECT_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	EGG="SQLObject==${SQLOBJECTVER}" \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

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
