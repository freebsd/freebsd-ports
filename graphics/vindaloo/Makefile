# New ports collection makefile for:    vindaloo
# Date created:         15 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vindaloo
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/Vindaloo/
DISTNAME=	Vindaloo-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PDF Reader for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	PopplerKit:${POPPLERKIT_PORT}

WRKSRC=		${WRKDIR}/Vindaloo

POPPLERKIT_PORT?=	graphics/popplerkit

.include <bsd.port.mk>
