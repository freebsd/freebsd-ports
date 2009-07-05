# New ports collection makefile for:    position
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	position
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	astro gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/position/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GPS and Moving-Map Applikation

BUILD_DEPENDS=	${LOCALBASE}/lib/libproj.a:${PORTSDIR}/${PROJ4_PORT}
RUN_DEPENDS=	${LOCALBASE}/lib/libproj.a:${PORTSDIR}/${PROJ4_PORT}

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Position/Position
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

PROJ4_PORT?=	misc/proj4

.include <bsd.port.mk>
