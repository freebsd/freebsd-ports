# New ports collection makefile for: py-mnemosyne
# Date created:		11 Jan 2008
# Whom:			Beech Rintoul <beech@FreeBSD.org>
#
#
# $FreeBSD$
#

PORTNAME=	mnemosyne
PORTVERSION=	1.2.1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}-proj/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

RUN_DEPENDS=	py*-game>=0:${PORTSDIR}/devel/py-game \
		py*-qt>=0:${PORTSDIR}/x11-toolkits/py-qt \
		${PYXML}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_EGG=	Mnemosyne-${PORTVERSION}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${PORTNAME}.png ${PREFIX}/share/icons

.include <bsd.port.mk>
