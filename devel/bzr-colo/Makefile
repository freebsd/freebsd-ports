# Ports collection makefile for:	bzr-colo
# Date created:		2010-10-18
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-colo
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/63041404/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Plugin for bzr to support colocated branches

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_colo

.include <bsd.port.mk>
