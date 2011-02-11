# Ports collection makefile for:        qbzr
# Date created:         26 May 2010
# Whom:                 Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	qbzr
PORTVERSION=	0.20.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/63505759/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Qt interface for bzr

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4 \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_QT_VER=	4
USE_PYDISTUTILS=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
