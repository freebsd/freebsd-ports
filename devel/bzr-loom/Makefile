# Ports collection makefile for:	bzr-loom
# Date created:				22 Aug 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-loom
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/44888887/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Bazaar plugin to assist in developing focused patches

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Loom
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.0final0

.include <bsd.port.mk>
