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
NO_BUILD=	yes

GADFLYDIR=	${PYTHON_SITELIBDIR}/gadfly

do-install:
	${MKDIR} ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${GADFLYDIR}
	${INSTALL_DATA} ${WRKSRC}/sql.mar ${GADFLYDIR}
	${ECHO_CMD} 'gadfly' > ${PYTHON_SITELIBDIR}/gadfly.pth
	(cd ${GADFLYDIR}; ${PYTHON_CMD} gfinstall.py)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${GADFLYDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${GADFLYDIR}
.if !defined(${NOPORTDOCS})
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/gadfly.JPG ${DOCSDIR}
.endif

.include <bsd.port.mk>
