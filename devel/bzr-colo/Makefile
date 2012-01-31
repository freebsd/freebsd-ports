# Ports collection makefile for:	bzr-colo
# Date created:		2010-10-18
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-colo
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/91504187/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Plugin for bzr to support colocated branches

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_colo

.include <bsd.port.mk>
