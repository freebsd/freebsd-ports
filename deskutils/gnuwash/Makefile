# New ports collection makefile for:    gnuwash
# Date created:         16 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnuwash
PORTVERSION=	0.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gnuwash.app
DISTNAME=	${PORTNAME}.app_${PORTVERSION}.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Configurable GNUstep timer application

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
ALL_TARGET=

.include <bsd.port.mk>
