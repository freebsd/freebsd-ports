# Created by: Dryice Dong Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	sqlalchemy
PORTVERSION=	0.7.10
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLAlchemy-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python SQL toolkit and Object Relational Mapper

LICENSE=	MIT

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

# Python3 ready
USES=		python
USE_PYTHON=	distutils autoplist
PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--no-diffs --nobackups --verbose --write

OPTIONS_DEFINE=		DOCS EXAMPLES TESTS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MSSQL MYSQL PGSQL SQLITE SYBASE
OPTIONS_DEFAULT=	SQLITE

MSSQL_DESC=	MS SQL Server backend
TESTS_DESC=	Include nose for unit tests
SYBASE_DESC=	Sybase backend

.include <bsd.port.options.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
AL_PORTDOCS=	*.html *.js
AL_PORTDOCS_SUBDIR=	core dialects orm
.endif

.if ${PORT_OPTIONS:MMSSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:databases/py-mssql
.endif

.if ${PORT_OPTIONS:MMYSQL}
.if ${PYTHON_VER} < 3.0
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb
#.else
# At the moment databases/py-pymysql does not build with Python3
# See https://github.com/petehunt/PyMySQL#python-3-0-support
#RUN_DEPENDS+=	pymysql>=0.5:databases/py-pymysql
.endif
.endif

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSYBASE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Sybase.py:databases/py-sybase
.endif

post-patch:
	${REINPLACE_CMD} -e 's/import logging/&.handlers/1' -i.bak ${WRKSRC}/test/engine/test_execute.py

pre-build:
.if ${PYTHON_REL} >= 3000
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/lib
.endif

post-install:
.if ${PYTHON_REL} >= 3000
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/doc
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${AL_PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${AL_PORTDOCS_SUBDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	@cd ${WRKSRC}/doc/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${i}
.endfor

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.if ${PYTHON_REL} >= 3000
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.endif
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.if ${PYTHON_REL} < 3000
PLIST_SUB+=	SPEEDUPS=""
.else
# C extensions are not supported in py3k
PLIST_SUB+=	SPEEDUPS="@comment "
.endif

regression-test: build
.if ${PYTHON_REL} >= 3000
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/test
.endif
	@cd ${WRKSRC} && ${PYTHON_CMD} sqla_nose.py

.include <bsd.port.post.mk>
