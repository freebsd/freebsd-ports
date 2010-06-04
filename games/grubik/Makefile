# New ports collection makefile for:    grubik
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	grubik
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	games gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/Recreational/
DISTNAME=	GRubik
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Virtual 3D Rubiks cube for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${RMDIR} ${WRKSRC}/GRubik.app/ix86/linux-gnu
	${RMDIR} ${WRKSRC}/GRubik.app/ix86

.include <bsd.port.mk>
