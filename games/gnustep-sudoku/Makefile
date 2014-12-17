# $FreeBSD$

PORTNAME=	sudoku
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	Sudoku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sudoku solver and generator

LICENSE=	GPLv3 # or later

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Sudoku.app/Sudoku

.include <bsd.port.mk>
