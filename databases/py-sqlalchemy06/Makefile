# Created by: Dryice Dong Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	sqlalchemy06
PORTVERSION=	0.6.9
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SQLAlchemy-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python SQL toolkit and Object Relational Mapper (series 0.6)

LICENSE=	MIT

# Python3 ready
USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	CEXTENSIONS DOCS EXAMPLES NOSE

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	MSSQL MYSQL PGSQL SQLITE SYBASE

OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE

CEXTENSIONS_DESC=	C extension to speed up the SQL layer
MSSQL_DESC=	MS SQL Server backend
NOSE_DESC=	Use Nose for unit tests
SYBASE_DESC=	Sybase backend

.include <bsd.port.options.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCEXTENSIONS} && ${PYTHON_REL} < 3000
PLIST_SUB+=	SPEEDUPS=""
.else
PLIST_SUB+=	SPEEDUPS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
AL_PORTDOCS=	*.html *.js
AL_PORTDOCS_SUBDIR=	core dialects orm
.endif

.if ${PORT_OPTIONS:MMSSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:databases/py-mssql
.endif

.if ${PORT_OPTIONS:MMYSQL} && ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MNOSE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=1.0.0:devel/py-nose
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
.if ${PORT_OPTIONS:MCEXTENSIONS} && ${PYTHON_REL} < 3000
	@${REINPLACE_CMD} -e 's|BUILD_CEXTENSIONS = False|BUILD_CEXTENSIONS = True|' \
		${WRKSRC}/setup.py
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${AL_PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${AL_PORTDOCS_SUBDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	@cd ${WRKSRC}/doc/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
