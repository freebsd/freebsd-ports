# Ports collection makefile for:	bazaar-ng
# Date created:		10 October 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bazaar-ng
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.bazaar-ng.org/pkg/
MASTER_SITE_SUBDIR=	gnu-arch
DISTNAME=	bzr-${PORTVERSION}

MAINTAINER=	lulf@kerneled.org
COMMENT=	An implementation of the GNU arch RCS protocol by Canonical

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

MAN1=		bzr.1

test:
	cd ${WRKSRC} && ./bzr selftest

post-build:
	cd ${WRKSRC} && ${PYTHON_CMD} bzr-man.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
