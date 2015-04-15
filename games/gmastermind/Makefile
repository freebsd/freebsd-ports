# $FreeBSD$

PORTNAME=	gmastermind
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	GMastermind-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Well-known mastermind game

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/GMastermind.app/GMastermind

.include <bsd.port.mk>
