# Ports collection makefile for:	bzr-builder
# Date created:				22 Aug 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-builder
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/54689925/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	A bzr plugin to construct a bzr branch based on a "recipe"

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_builder

post-patch:
	@${REINPLACE_CMD} -e 's|0.4|0.5|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
