# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	lapispuzzle
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	LapisPuzzle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tetris-like game for GNUstep

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/LapisPuzzle-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/LapisPuzzle.app/LapisPuzzle

.include <bsd.port.mk>
