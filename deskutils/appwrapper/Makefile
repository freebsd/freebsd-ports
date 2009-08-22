# New ports collection makefile for:    appwrapper
# Date created:         16 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	appwrapper
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AppWrapper%20${PORTVERSION}
DISTNAME=	AppWrapper.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep application wrapper

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/AppWrapper

post-patch:
	${RMDIR} ${WRKSRC}/AppWrapper.app/ix86/linux-gnu
	${RMDIR} ${WRKSRC}/AppWrapper.app/ix86

.include <bsd.port.mk>
