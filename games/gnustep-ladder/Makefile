# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	ladder
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Ladder-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Go frontend for GNUstep

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

RUN_DEPENDS=	gnugo:${PORTSDIR}/games/gnugo

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Ladder.app/Ladder

.include <bsd.port.mk>
