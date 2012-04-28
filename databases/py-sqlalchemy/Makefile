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
OPTIONS+=	PGSQL "support PostGreSQL" on
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

.if !defined(WITHOUT_MYSQL) && ${PYTHON_VER} < 3.0
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_NOSE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose-1.0.0:${PORTSDIR}/devel/py-nose
.endif

.if !defined(WITHOUT_PGSQL)
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

# When Python version is 3.2+ we rewrite all the filenames
# of TMPPLIST that end with .py[co], so that they conform
# to PEP 3147 (see http://www.python.org/dev/peps/pep-3147/)
.if ${PYTHON_REL} >= 320
PYMAGICTAG=	${PYTHON_CMD} -c 'import imp; print(imp.get_tag())'
add-plist-post:
	@${AWK} '\
		/\.py[co]$$/ && !($$0 ~ "/" pc "/") {id = match($$0, /\/[^\/]+\.py[co]$$/); if (id != 0) {d = substr($$0, 1, RSTART - 1); dirs[d] = 1}; sub(/\.py[co]$$/,  "." mt "&"); sub(/[^\/]+\.py[co]$$/, pc "/&"); print; next} \
		/^@dirrm / {d = substr($$0, 8); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		{print} \
		END {if (sp in dirs) {print "@dirrm " sp "/" pc}} \
		' \
		pc="__pycache__" mt="$$(${PYMAGICTAG})" sp="${PYTHON_SITELIBDIR:S,${PYTHONBASE}/,,g}" \
		${TMPPLIST} > ${TMPPLIST}.pyc_tmp
	@${MV} ${TMPPLIST}.pyc_tmp ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
