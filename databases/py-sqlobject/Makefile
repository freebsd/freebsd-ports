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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formencode>=1.2.2:www/py-formencode@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		python${PY_MYSQL}
USE_PYTHON=	autoplist distutils

# currently MaxDB(SAP), ADODB are not supported
OPTIONS_DEFINE=	MYSQL PGSQL SQLITE MSSQL SYBASE
SYBASE_DESC=	sybase support

PORTDOCS=	*

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb@${FLAVOR}
MYSQL_VARS=	PY_MYSQL=:2.7
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR}
MSSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymssql>=0:databases/py-pymssql@${FLAVOR}
SYBASE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sybase>=0.37:databases/py-sybase@${FLAVOR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
