# Ports collection makefile for:	py-sqlobject
# Date created:				24 June 2004
# Whom:					"Choe, Cheng-Dae" whitekid
#
# $FreeBSD$
#

PORTNAME=	sqlobject
PORTVERSION=	0.12.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A python object for manipulation with SQL table row

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formencode>=1.2.2:${PORTSDIR}/www/py-formencode

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	SQLObject
PYDISTUTILS_NOEGGINFO=	yes

PORTDOCS=	*

OPTIONS=	MYSQL	"MySQL supports" off \
		PGSQL	"PostgreSQL Supports" off \
		SQLITE	"SQLite Supports" off \
		MSSQL	"MSSQL Supports" off \
		FIREBIRD "FireBird Supports" Off \
		SYBASE  "Sybase Supports" Off

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>
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

.if defined(WITH_FIREBIRD)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}kinterbasdb>=3.2:${PORTSDIR}/databases/kinterbasdb
.endif

.if defined(WITH_SYBASE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sybase>=0.37:${PORTSDIR}/databases/py-sybase
.endif

# currently MaxDB(SAP), ADODB are not supported

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
