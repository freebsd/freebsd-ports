# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qct
PORTVERSION=	1.7
PORTREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	http://qct.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QCT GUI commit tool

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/qct
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/qct.1.txt ${DOCSDIR}/qct.1.txt
.endif

.include <bsd.port.mk>
