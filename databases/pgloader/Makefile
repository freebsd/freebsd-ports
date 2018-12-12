# Created by: Pierre-Emmanuel Andre
# $FreeBSD$

PORTNAME=	pgloader
PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1814/

MAINTAINER=	pea@raveland.org
COMMENT=	Import CSV data and Large Object to PostgreSQL

NO_BUILD=	yes
USES=		python:2.7 shebangfix
SHEBANG_FILES=	*.py

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:databases/py-psycopg2@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/share/python-support,${PYTHON_SITELIBDIR},' ${WRKSRC}/pgloader/options.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgloader.py ${STAGEDIR}${PREFIX}/bin/pgloader
	${INSTALL_MAN} ${WRKSRC}/pgloader.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/pgloader
	@cd ${WRKSRC}/pgloader && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYTHON_SITELIBDIR}/pgloader/
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/pgloader/reformat
	@cd ${WRKSRC}/reformat && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYTHON_SITELIBDIR}/pgloader/reformat/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pgloader.1.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
