PORTNAME=	gmines
PORTVERSION=	0.2
PORTREVISION=	10
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GMines-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Well-known minesweeper game for GNUstep
WWW=		https://gap.nongnu.org/gmines/

LICENSE=	GPLv2+

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GMines.app/GMines

.include <bsd.port.mk>
