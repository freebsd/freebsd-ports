# New ports collection makefile for:	drm
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		drm
PORTVERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
DISTNAME=		dr_mario
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Very simple tetris-style game

ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bugs ${PREFIX}/bin/drm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
