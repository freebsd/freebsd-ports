# Created by: "Choe, Cheng-Dae" whitekid
# $FreeBSD$

PORTNAME=	sqlobject
PORTVERSION=	1.3.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A python object for manipulation with SQL table row

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formencode>=1.2.2:${PORTSDIR}/www/py-formencode
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	SQLObject
PYDISTUTILS_NOEGGINFO=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE MSSQL FIREBIRD SYBASE
SYBASE_DESC=	sybase support

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PORTDOCS=	*
.if empty(PORT_OPTIONS:MDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.else
PLIST_SUB+=	PORTDOCS=""
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MMSSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}kinterbasdb>=3.2:${PORTSDIR}/databases/kinterbasdb
.endif

.if ${PORT_OPTIONS:MSYBASE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sybase>=0.37:${PORTSDIR}/databases/py-sybase
.endif

# currently MaxDB(SAP), ADODB are not supported

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
