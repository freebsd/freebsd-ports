# New ports collection makefile for: py-mnemosyne
# Date created:		11 Jan 2008
# Whom:			Beech Rintoul <beech@FreeBSD.org>
#
#
# $FreeBSD$
#

PORTNAME=	mnemosyne
PORTVERSION=	1.1.1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}-proj/OldFiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mnemosyne-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_EGG=	Mnemosyne-${PORTVERSION}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		py*-xml>=0:${PORTSDIR}/textproc/py-xml \
		py*-qt>=0:${PORTSDIR}/x11-toolkits/py-qt

post-install:
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/mnemosyne.desktop ${PREFIX}/share/applications/
	@${INSTALL} -d ${PREFIX}/share/icons
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/mnemosyne.png ${PREFIX}/share/icons/

.include <bsd.port.mk>
