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
DISTNAME=	kwP

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes

GADFLYDIR=	${PYTHON_SITELIBDIR}/gadfly
GADFLYDOCDIR=	${PREFIX}/share/doc/gadfly

do-build:

do-install:
	${MKDIR} ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/sql.mar ${GADFLYDIR}
	${ECHO} 'gadfly' > ${PYTHON_SITELIBDIR}/gadfly.pth
	(cd ${GADFLYDIR}; ${PYTHON_CMD} gfinstall.py)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${GADFLYDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${GADFLYDIR}
	${MKDIR} ${GADFLYDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${GADFLYDOCDIR}
.if !defined(${NOPORTDOCS})
	${INSTALL_DATA} ${WRKSRC}/*.html ${GADFLYDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gadfly.JPG ${GADFLYDOCDIR}
.endif

.include <bsd.port.mk>
