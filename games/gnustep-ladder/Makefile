# New ports collection makefile for:    ladder
# Date created:         11 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	ladder
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		${MASTER_SITE_GNUSTEP_CH}
MASTER_SITE_SUBDIR=	gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Ladder-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Go frontend for GNUstep

RUN_DEPENDS=	gnugo:${PORTSDIR}/games/gnugo

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
