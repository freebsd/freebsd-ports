PORTNAME=	ladder
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Ladder-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Go frontend for GNUstep
WWW=		https://www.nongnu.org/gap/ladder/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

RUN_DEPENDS=	gnugo:games/gnugo

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Ladder.app/Ladder

.include <bsd.port.mk>
