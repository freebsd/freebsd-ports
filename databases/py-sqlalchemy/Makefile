# Created by: Dryice Dong Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	sqlalchemy
PORTVERSION=	0.7.10
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	07
DISTNAME=	SQLAlchemy-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python SQL toolkit and Object Relational Mapper

LICENSE=	MIT

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PY2TO3_CMD=		${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=		--no-diffs --nobackups --verbose --write
PYDISTUTILS_INSTALLARGS=	--always-unzip \
				--install-dir ${PYEASYINSTALL_SITELIBDIR} \
				--no-deps \
				--optimize 2 \
				--quiet \
				--script-dir ${PYEASYINSTALL_BINDIR} \
				--site-dir ${PYEASYINSTALL_SITELIBDIR} \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}
PYDISTUTILS_PKGNAME=	SQLAlchemy
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
PYDISTUTILS_NOEGGINFO=	yes
PYEASYINSTALL_ARCHDEP=	yes

OPTIONS_DEFINE=		DOCS EXAMPLES TESTS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	FIREBIRD MSSQL MYSQL PGSQL SQLITE SYBASE
OPTIONS_DEFAULT=	SQLITE

FIREBIRD_DESC=	Firebird backend
MSSQL_DESC=	MS SQL Server backend
TESTS_DESC=	Include nose for unit tests
SYBASE_DESC=	Sybase backend

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
AL_PORTDOCS=	*.html *.js
AL_PORTDOCS_SUBDIR=	core dialects orm
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/kinterbasdb/__init__.py:${PORTSDIR}/databases/kinterbasdb
.endif

.if ${PORT_OPTIONS:MMSSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

.if ${PORT_OPTIONS:MMYSQL}
.if ${PYTHON_VER} < 3.0
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
#.else
# At the moment databases/py-pymysql does not build with Python3
# See https://github.com/petehunt/PyMySQL#python-3-0-support
#RUN_DEPENDS+=	pymysql>=0.5:${PORTSDIR}/databases/py-pymysql
.endif
.endif

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSYBASE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Sybase.py:${PORTSDIR}/databases/py-sybase
.endif

post-patch:
	${REINPLACE_CMD} -e 's/import logging/&.handlers/1' -i.bak ${WRKSRC}/test/engine/test_execute.py

pre-build:
.if ${PYTHON_REL} >= 300
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/lib
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
.if ${PYTHON_REL} >= 300
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/doc
.endif
	@${MKDIR} ${DOCSDIR}
.for i in ${AL_PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.for i in ${AL_PORTDOCS_SUBDIR}
	${MKDIR} ${DOCSDIR}/${i}
	@cd ${WRKSRC}/doc/${i} && ${COPYTREE_SHARE} . ${DOCSDIR}/${i}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.if ${PYTHON_REL} >= 300
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.endif
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
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

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

regression-test: build
.if ${PYTHON_REL} >= 300
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/test
.endif
	@cd ${WRKSRC} && ${PYTHON_CMD} sqla_nose.py

.include <bsd.port.post.mk>
