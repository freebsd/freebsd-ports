# New ports collection makefile for:	py-qt4-qct
# Date created:				10 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qct
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://qct.sourceforge.net/
MASTER_SITE_SUBDIR=	qct
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	QCT GUI commit tool

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes

DOCSDIR=	${TARGETDIR}/share/doc/py-qt4-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/qct.1.txt ${DOCSDIR}/qct.1.txt
.endif

.include <bsd.port.mk>
