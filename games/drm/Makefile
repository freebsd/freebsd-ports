# New ports collection makefile for:	drm
# Version required:			1.0
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		dr_mario
PKGNAME=		drm-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bugs ${PREFIX}/bin/drm
.if !defined(NOPORTDOCS)
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.drm
.endif

.include <bsd.port.mk>
