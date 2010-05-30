# New ports collection makefile for:    nextgo
# Date created:         05 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	nextgo
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	NeXTGo-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	classic Go game for OPENSTEP/GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile
	${REINPLACE_CMD} -e 's|PSWait|myPSWait|' \
		${WRKSRC}/Board.m

.include <bsd.port.mk>
