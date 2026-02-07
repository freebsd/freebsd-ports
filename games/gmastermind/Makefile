PORTNAME=	gmastermind
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GMastermind-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Well-known mastermind game
WWW=		https://gap.nongnu.org/gmastermind/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GMastermind.app/GMastermind

.include <bsd.port.mk>
