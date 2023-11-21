PORTNAME=	sqlobject
PORTVERSION=	3.11.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLObject-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python object for manipulation with SQL table row
WWW=		http://www.sqlobject.org

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formencode>=1.2.2:www/py-formencode@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		dos2unix python
USE_PYTHON=	autoplist distutils

# currently MaxDB(SAP), ADODB are not supported
OPTIONS_DEFINE=	DOCS PGSQL SQLITE MSSQL

PORTDOCS=	*

PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}
MSSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymssql>=0:databases/py-pymssql@${PY_FLAVOR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
