# Ports collection makefile for:	bzr-loom
# Date created:				22 Aug 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-loom
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/94514373/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Bazaar plugin to assist in developing focused patches

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Loom
PYDISTUTILS_PKGVERSION=	2.2.1dev0

.include <bsd.port.mk>
