# New ports collection makefile for:    ladder.app
# Date created:         11 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	ladder
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://download.savannah.gnu.org/releases/gap/ \
		http://io.debian.net/~tar/ports/distfiles/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Ladder-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNU Go frontend for GNUstep

RUN_DEPENDS=	gnugo:${PORTSDIR}/games/gnugo

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
