# New ports collection makefile for:    ladder
# Date created:         11 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	ladder
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games gnustep
MASTER_SITES=	http://download.savannah.gnu.org/releases/gap/ \
		${MASTER_SITE_GNUSTEP_CH}
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Ladder-${PORTVERSION}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	GNU Go frontend for GNUstep

RUN_DEPENDS=	gnugo:${PORTSDIR}/games/gnugo

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
