# Ports collection makefile for:	bzr-builder
# Date created:				22 Aug 2010
# Whom:					Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	bzr-builder
PORTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/84852974/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A bzr plugin to construct a bzr branch based on a "recipe"

LICENSE=	GPLv3

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_builder

.include <bsd.port.mk>
