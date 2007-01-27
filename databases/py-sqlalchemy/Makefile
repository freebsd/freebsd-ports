# Ports collection makefile for:	py-sqlalchemy
# Date created:				12 Auguest 2004
# Whom:					Dryice Dong Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	sqlalchemy
PORTVERSION=	0.3.3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://cheeseshop.python.org/packages/source/S/SQLAlchemy/ \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	sqlalchemy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLAlchemy-${PORTVERSION}

MAINTAINER=	dryice@dryice.name
COMMENT=	A Python SQL toolkit and Object Relational Mapper

USE_PYTHON=	2.3+
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHONVERSION=${_PYTHON_VERSION} \
		EXAMPLEDIR=share/examples/${PORTNAME}
USE_PYDISTUTILS=	yes

BUILD_DEPENDS+=		easy_install:${PORTSDIR}/devel/py-setuptools

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS=	FIREBIRD "support FireBird" off
OPTIONS+=	MSSQL "support MS SQL Server" off
OPTIONS+=	MYSQL "support MySql" on
OPTIONS+=	POSTGRE "support PostGreSQL" on
OPTIONS+=	SQLITE "support Sqlite" on

.if !defined(NOPORTDOCS)
PORTDOCS=	adv_datamapping.html alphaapi.html \
		alphaimplementation.html datamapping.html \
		dbengine.html docs.css docstrings.html \
		documentation.html index.html metadata.html \
		plugins.html pooling.html scripts.js \
		sqlconstruction.html style.css syntaxhighlight.css \
		tutorial.html types.html unitofwork.html
.endif

PORTEXAMPLES=	adjacencytree association backref collections graphs \
	pickle polymorph vertical

.include <bsd.port.pre.mk>

.if defined(WITH_FIREBIRD)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/kinterbasdb/__init__.py:${PORTSDIR}/databases/kinterbasdb
.endif

.if defined(WITH_MSSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

.if !defined(WITHOUT_POSTGRE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.endif

.if !defined(WITHOUT_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

	${MKDIR} ${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	${CP} -r ${WRKSRC}/examples/${i} ${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
