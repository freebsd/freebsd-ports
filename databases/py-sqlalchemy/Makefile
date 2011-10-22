# Ports collection makefile for:	py-sqlalchemy
# Date created:				12 August 2004
# Whom:					Dryice Dong Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	sqlalchemy
PORTVERSION=	0.7.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLAlchemy-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python SQL toolkit and Object Relational Mapper

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	SQLAlchemy
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
PYDISTUTILS_NOEGGINFO=	yes
PYEASYINSTALL_ARCHDEP=	yes

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS=	FIREBIRD "support FireBird" off
OPTIONS+=	MSSQL "support MS SQL Server" off
OPTIONS+=	MYSQL "support MySql" on
OPTIONS+=	NOSE "install Nose for unit tests" off
OPTIONS+=	POSTGRE "support PostGreSQL" on
OPTIONS+=	SQLITE "support Sqlite" on
OPTIONS+=	SYBASE "support Sybase" off

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
AL_PORTDOCS=	*.html *.js
AL_PORTDOCS_SUBDIR=	core dialects orm
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FIREBIRD)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/kinterbasdb/__init__.py:${PORTSDIR}/databases/kinterbasdb
.endif

.if defined(WITH_MSSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_NOSE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose-1.0.0:${PORTSDIR}/devel/py-nose
.endif

.if !defined(WITHOUT_POSTGRE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:${PORTSDIR}/databases/py-psycopg2
.endif

.if !defined(WITHOUT_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if !defined(WITHOUT_SYBASE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Sybase.py:${PORTSDIR}/databases/py-sybase
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${AL_PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.for i in ${AL_PORTDOCS_SUBDIR}
	${MKDIR} ${DOCSDIR}/${i}
	@cd ${WRKSRC}/doc/${i} && ${COPYTREE_SHARE} . ${DOCSDIR}/${i}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.if ${PYTHON_REL} < 300
PLIST_SUB+=	SPEEDUPS=""
.else
# C extensions are not supported in py3k
PLIST_SUB+=	SPEEDUPS="@comment "
PYEASYINSTALL_OSARCH=

easyinstall-setopt:
	${DO_NADA}
.endif

.include <bsd.port.post.mk>
