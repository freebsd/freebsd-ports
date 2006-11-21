# New ports collection makefile for:    lapispuzzle
# Date created:         13 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	lapispuzzle
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://download.savannah.gnu.org/releases/gap/ \
		http://io.debian.net/~tar/ports/distfiles/
DISTNAME=	LapisPuzzle-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Tetris-like game for GNUstep

WRKSRC=		${WRKDIR}/LapisPuzzle-${PORTVERSION}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
