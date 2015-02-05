# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gomoku
PORTVERSION=	1.2.9
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	http://www.gnustep.it/nicola/Applications/Gomoku/
DISTNAME=	Gomoku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep Gomoku game

LICENSE=	GPLv2 # or later

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Gomoku.app/Gomoku

.include <bsd.port.mk>
