# New ports collection makefile for:    gadfly
# Date created:         30 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gadfly
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.chordate.com/kwParsing/
DISTNAME=       kwP

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_WRKSUBDIR=	yes

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
GADFLYDIR=	${PYTHONSCRIPTDIR}/site-packages/gadfly
GADFLYDOCDIR=	${PREFIX}/share/doc/gadfly

do-build:

do-install:
	${MKDIR} ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/sql.mar ${GADFLYDIR}
	${ECHO} 'gadfly' > ${PYTHONSCRIPTDIR}/site-packages/gadfly.pth
	(cd ${GADFLYDIR}; python gfinstall.py)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${GADFLYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${GADFLYDIR}
	${MKDIR} ${GADFLYDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${GADFLYDOCDIR}
.if !defined(${NOPORTDOCS})
	${INSTALL_DATA} ${WRKSRC}/*.html ${GADFLYDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gadfly.JPG ${GADFLYDOCDIR}
.endif

.include <bsd.port.mk>
