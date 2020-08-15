# Created by: Dryice Dong Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	sqlalchemy
PORTVERSION=	1.0.14
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	10
DISTNAME=	SQLAlchemy-${DISTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python SQL toolkit and Object Relational Mapper 1.0.x

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--no-diffs --nobackups --verbose --write
TEST_TARGET=	do-test

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}sqlalchemy0[6789]* ${PYTHON_PKGNAMEPREFIX}sqlalchemy1[12]

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MSSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MSSQL_DESC=	MS SQL Server backend

MSSQL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pymssql.py:databases/py-pymssql@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

PORTDOCS=		*
PORTEXAMPLES=		*

.include <bsd.port.pre.mk>

pre-build:
.if ${PYTHON_REL} >= 3000
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/lib
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/doc
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.endif

# C extensions are not supported with all versions of Python, so ignore
# errors here if there are no .so files to strip.
post-install:
	-@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sqlalchemy/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
.if ${PYTHON_REL} >= 3000
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/test
.endif
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
