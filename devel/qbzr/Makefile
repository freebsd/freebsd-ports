# Ports collection makefile for:        qbzr
# Date created:         26 May 2010
# Whom:                 C-S
#
# $FreeBSD$
#

PORTNAME=	qbzr
PORTVERSION=	0.18.6
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/47816511/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Qt interface to Bazaar-NG VCS

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4 \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC= ${WRKDIR}/${PORTNAME}

USE_PYTHON=	2.4+
USE_QT_VER=     4
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
