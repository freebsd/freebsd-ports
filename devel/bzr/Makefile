# Ports collection makefile for:	bazaar-ng
# Date created:		10 October 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bazaar-ng
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://bazaar-vcs.org/pkg/ \
		http://voodoo.bawue.com/download/
MASTER_SITE_SUBDIR=	gnu-arch
DISTNAME=	bzr-${PORTVERSION}

MAINTAINER=	lulf@stud.ntnu.no
COMMENT=	A Python implementation of the GNU arch RCS protocol by Canonical

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

MAN1=		bzr.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${MAN1PREFIX}/man/man1

test:	build
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.mk>
