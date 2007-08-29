# Ports collection makefile for:	bzrtools
# Date created:		3 November 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bzrtools
PORTVERSION=	0.90.0
CATEGORIES=	devel
MASTER_SITES=	http://panoramicfeedback.com/opensource/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extensions to devel/bazaar-ng

RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		rsync:${PORTSDIR}/net/rsync \
		dot:${PORTSDIR}/graphics/graphviz

WRKSRC=	${WRKDIR}/bzrtools
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	BzrTools

.include <bsd.port.mk>
