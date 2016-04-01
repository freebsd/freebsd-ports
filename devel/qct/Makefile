# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qct
PORTVERSION=	1.7
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	http://qct.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QCT GUI commit tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui

USES=		python
USE_PYTHON=	distutils
WRKSRC=		${WRKDIR}/qct

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/qct.1.txt ${STAGEDIR}${DOCSDIR}/qct.1.txt

.include <bsd.port.mk>
