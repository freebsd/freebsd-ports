# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mnemosyne
PORTVERSION=	2.2a
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-2.2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	marekrud@gmail.com
COMMENT=	Flash-card tool which optimises your learning process

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4>=4.5:${PORTSDIR}/devel/py-qt4 \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1.1:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2:${PORTSDIR}/www/py-cherrypy

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Mnemosyne

NO_STAGE=	yes
post-install:
	@cd ${WRKSRC}/mo && ${COPYTREE_SHARE} . ${PREFIX}/share/locale
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${PORTNAME}.png ${PREFIX}/share/icons

.include <bsd.port.mk>
