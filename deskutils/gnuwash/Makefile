# New ports collection makefile for:    gnuwash
# Date created:         16 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnuwash
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gnuwash.app
DISTNAME=	${PORTNAME}.app_${PORTVERSION}.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Configurable GNUstep timer application

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
