# New ports collection makefile for:	pgloader
# Date created:		2008-06-02
# Whom:			Pierre-Emmanuel Andre
#
# $FreeBSD$
#

PORTNAME=	pgloader
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1814/

MAINTAINER=	pea@raveland.org
COMMENT=	Import CSV data and Large Object to PostgreSQL

MAN1=		pgloader.1

NO_BUILD=	yes
USE_PYTHON=	2.5+

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/share/python-support,${PYTHON_SITELIBDIR},' ${WRKSRC}/pgloader/options.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgloader.py ${PREFIX}/bin/pgloader
	${INSTALL_MAN} ${WRKSRC}/pgloader.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${PYTHON_SITELIBDIR}/pgloader
	@cd ${WRKSRC}/pgloader && ${COPYTREE_SHARE} \* ${PYTHON_SITELIBDIR}/pgloader/
	${MKDIR} ${PYTHON_SITELIBDIR}/pgloader/reformat
	@cd ${WRKSRC}/reformat && ${COPYTREE_SHARE} \* ${PYTHON_SITELIBDIR}/pgloader/reformat/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pgloader.1.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
