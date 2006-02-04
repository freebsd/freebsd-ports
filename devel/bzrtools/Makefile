# Ports collection makefile for:	bzrtools
# Date created:		3 November 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bzrtools
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://panoramicfeedback.com/opensource/

MAINTAINER=	lulf@kerneled.org
COMMENT=	Extensions to devel/bazaar-ng

RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		rsync:${PORTSDIR}/net/rsync \
		dot:${PORTSDIR}/graphics/graphviz

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
