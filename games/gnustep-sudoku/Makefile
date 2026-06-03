PORTNAME=	sudoku
PORTVERSION=	0.7
PORTREVISION=	10
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Sudoku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sudoku solver and generator
WWW=		https://gap.nongnu.org/sudoku/index.html

LICENSE=	GPLv3+

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Sudoku.app/Sudoku

.include <bsd.port.mk>
