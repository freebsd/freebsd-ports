# Created by: "Choe, Cheng-Dae" whitekid
# $FreeBSD$

PORTNAME=	sqlobject
PORTVERSION=	1.6.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python object for manipulation with SQL table row

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formencode>=1.2.2:www/py-formencode@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		python${PY_MYSQL}
USE_PYTHON=	autoplist distutils

# currently MaxDB(SAP), ADODB are not supported
OPTIONS_DEFINE=	DOCS MYSQL PGSQL SQLITE MSSQL

PORTDOCS=	*

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb@${PY_FLAVOR}
MYSQL_VARS=	PY_MYSQL=:2.7
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}
MSSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymssql>=0:databases/py-pymssql@${PY_FLAVOR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
