# Ports collection makefile for:	bzr-stats
# Date created:				2011-02-27
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-stats
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/65203347/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Simple statistics plugin for bzr

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_stats

.include <bsd.port.mk>
